// Fill out your copyright notice in the Description page of Project Settings.

#include "MechaPlayerController.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text)

AMecha* AMechaPlayerController::GetControlledMecha() const
{
	return Cast<AMecha>(GetPawn());
}

void AMechaPlayerController::BeginPlay()
{
	Super::BeginPlay();
	print(TEXT("Launch Mission. Drop down Scout BattleMech..."));

	//UE_LOG(LogTemp, Warning, TEXT("AMechaPlayerController::BeginPlay()"));
	
	AMechaPlayerController::MechaUnderControl = AMechaPlayerController::GetControlledMecha();
	if (AMechaPlayerController::MechaUnderControl)
	{
		//UE_LOG(LogTemp, Warning, TEXT("AMechaPlayerController: Got control over Mecha %s"), *(AMechaPlayerController::MechaUnderControl->GetName()));
	}
}

void AMechaPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UE_LOG(LogTemp, Warning, TEXT("AMechaPlayerController: Tick %f"), DeltaTime);

	AMechaPlayerController::AimTowardsCrosshair();
}

void AMechaPlayerController::AimTowardsCrosshair()
{
	if (!AMechaPlayerController::MechaUnderControl) { return; }

	FVector HitLocation; // Out param
	if (GetSightRayHitLocation(HitLocation))
	{
		AMechaPlayerController::MechaUnderControl->AimAt(HitLocation);
	}
}

bool AMechaPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find Crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX*CrosshairScreenXLocation, ViewportSizeY*CrosshairScreenYLocation);
	
	FVector LookDirection;
	
	if (AMechaPlayerController::GetLookDirection(ScreenLocation, LookDirection))
	{
		//UE_LOG(LogTemp, Warning, TEXT("AMechaPlayerController: AimWorldDirection = %s"), *LookDirection.ToString());
		if (AMechaPlayerController::GetLookVectorHitLocation(LookDirection, OutHitLocation))
		{
			UE_LOG(LogTemp, Warning, TEXT("AMechaPlayerController: HitLocation = %s"), *OutHitLocation.ToString());

			UKismetSystemLibrary::DrawDebugPoint(
				GetWorld(),
				OutHitLocation,
				10,  					//size
				FColor(255, 0, 255),	//pink
				0.03 					//point leaves a trail on moving object
			);

			return true;
		}
	}

	return false;
}

bool AMechaPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& OutLookDirection) const
{
	FVector OutLookPosition;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, OutLookPosition, OutLookDirection);
}

bool AMechaPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const
{
	auto startTrace = PlayerCameraManager->GetCameraLocation();
	auto endTrace = startTrace + (AMechaPlayerController::LineTraceRange * LookDirection);
	FHitResult hitResult;
	FCollisionQueryParams collisionParams;
	collisionParams.AddIgnoredActor(Cast<AActor>(GetWorld()->GetFirstPlayerController()->GetPawn()));
	//collisionParams.AddIgnoredActor(Cast<AActor>(Player));
	if (GetWorld()->LineTraceSingleByChannel(
			hitResult, 
			startTrace, 
			endTrace, 
			ECollisionChannel::ECC_Visibility,
			collisionParams))
	{
		OutHitLocation = hitResult.Location;
		//UE_LOG(LogTemp, Warning, TEXT("AMechaPlayerController: HitResult = %s"), *(hitResult.GetActor()->GetName()));
		return true;
	}
	else
	{
		OutHitLocation = FVector(0.0f);
		return false;
	}
}