// ÷опирайт

#include "MechaPlayerController.h"
#include "MechAimingComponent.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text)

void AMechaPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto AimingComponent = GetPawn()->FindComponentByClass<UMechAimingComponent>();
	if (ensure(AimingComponent))
	{
		FindAimingComponent(AimingComponent);
	}
}

void AMechaPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

void AMechaPlayerController::AimTowardsCrosshair()
{
	auto AimingComponent = GetPawn()->FindComponentByClass<UMechAimingComponent>();
	if (ensure(AimingComponent))
	{
		FVector HitLocation; // Out param
		if (GetSightRayHitLocation(HitLocation))
		{
			AimingComponent->AimAt(HitLocation);
		}
	}
}

bool AMechaPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find Crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX*CrosshairScreenXLocation, ViewportSizeY*CrosshairScreenYLocation);
	
	FVector LookDirection;
	
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//UE_LOG(LogTemp, Warning, TEXT("AMechaPlayerController: AimWorldDirection = %s"), *LookDirection.ToString());
		if (GetLookVectorHitLocation(LookDirection, OutHitLocation))
		{
			//UE_LOG(LogTemp, Warning, TEXT("AMechaPlayerController: HitLocation = %s"), *OutHitLocation.ToString());

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
	auto endTrace = startTrace + (LineTraceRange * LookDirection);
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