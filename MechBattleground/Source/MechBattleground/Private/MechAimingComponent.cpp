// Fill out your copyright notice in the Description page of Project Settings.

#include "MechAimingComponent.h"
#include "MechTurret.h"
#include "MechCabin.h"


// Sets default values for this component's properties
UMechAimingComponent::UMechAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UMechAimingComponent::SetTurretGunReference(UMechTurret* GunToSet)
{
	UMechAimingComponent::GunTurret = GunToSet;
}

void UMechAimingComponent::SetTurretBarrelReference(UStaticMeshComponent* GunToSet)
{
	UMechAimingComponent::GunTurretBarrel = GunToSet;
}

void UMechAimingComponent::SetMechCabinReference(UMechCabin* CabToSet)
{
	UMechAimingComponent::MechCabin = CabToSet;
}

void UMechAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!UMechAimingComponent::GunTurret) { return; }
	if (!UMechAimingComponent::GunTurretBarrel) { return; }
	if (!UMechAimingComponent::MechCabin) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = UMechAimingComponent::GunTurretBarrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		moveTurret(AimDirection);
		//auto ourMechaName = GetOwner()->GetName();
		//auto turretLocation = UMechAimingComponent::GunTurret->GetComponentLocation();
		//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s from %s"), *ourMechaName, *HitLocation.ToString(), *turretLocation.ToString());

		//auto Time = GetWorld()->GetTimeSeconds();
		//UE_LOG(LogTemp, Warning, TEXT("%f: aiming solution found"), Time);
	}
	else
	{
		//auto Time = GetWorld()->GetTimeSeconds();
		//UE_LOG(LogTemp, Warning, TEXT("%f: aiming solution not found"), Time);
	}
}

void UMechAimingComponent::moveTurret(FVector AimDirection)
{
	//UE_LOG(LogTemp, Warning, TEXT("AimDirection: %s"), *(AimDirection.ToString()));
	auto TurretRotator = UMechAimingComponent::GunTurret->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - TurretRotator;

	UMechAimingComponent::GunTurret->Elevate(DeltaRotator.Pitch);
	UMechAimingComponent::MechCabin->LookRotate(DeltaRotator.Yaw);
}
