// Fill out your copyright notice in the Description page of Project Settings.

#include "MechAimingComponent.h"
#include "MechTurret.h"


// Sets default values for this component's properties
UMechAimingComponent::UMechAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

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

void UMechAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!UMechAimingComponent::GunTurret) { return; }
	if (!UMechAimingComponent::GunTurretBarrel) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = UMechAimingComponent::GunTurretBarrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		moveTurret(AimDirection);
		//auto ourMechaName = GetOwner()->GetName();
		//auto turretLocation = UMechAimingComponent::GunTurret->GetComponentLocation();
		//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s from %s"), *ourMechaName, *HitLocation.ToString(), *turretLocation.ToString());
	}
}

void UMechAimingComponent::moveTurret(FVector AimDirection)
{
	auto TurretRotator = UMechAimingComponent::GunTurret->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - TurretRotator;

	//TODO UMechAimingComponent::GunTurret->Elevate(5);
}
