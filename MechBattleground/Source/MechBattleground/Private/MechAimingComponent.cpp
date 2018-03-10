// ÷опирайты

#include "MechAimingComponent.h"
#include "MechTurret.h"
#include "MechCabin.h"
#include "Projectile.h"

// Sets default values for this component's properties
UMechAimingComponent::UMechAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UMechAimingComponent::Init(UMechCabin* cabinToSet, UStaticMeshComponent* gunTurretBarrelToSet, UMechTurret* gunTurretToSet)
{
	MechCabin = cabinToSet;
	GunTurretBarrel = gunTurretBarrelToSet;
	GunTurret = gunTurretToSet;
}

void UMechAimingComponent::FireMainWeapon()
{
	if (!ensure(GunTurretBarrel && ProjectileBlueprint)) { return; }

	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > turretReloadTime;

	if (isReloaded)
	{
		// Spawn projectile at the Socket location on the Turret
		auto projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			GunTurretBarrel->GetSocketLocation(FName("Projectile")),
			GunTurretBarrel->GetSocketRotation(FName("Projectile"))
			);
		projectile->LaunchProjectile(turretShootSpeed);

		LastFireTime = FPlatformTime::Seconds();
	}
}

void UMechAimingComponent::FireAltWeapon()
{
	//UE_LOG(LogTemp, Error, TEXT("AMecha::FireAltWeapon()"));
}

void UMechAimingComponent::AimAt(FVector HitLocation)
{
	if (!ensure(GunTurret && GunTurretBarrel && MechCabin)) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = GunTurretBarrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		turretShootSpeed,
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
	if (!ensure(GunTurret && MechCabin)) { return; }
	//UE_LOG(LogTemp, Warning, TEXT("AimDirection: %s"), *(AimDirection.ToString()));
	auto TurretRotator = UMechAimingComponent::GunTurret->GetForwardVector().Rotation();
	auto CabRotator = UMechAimingComponent::MechCabin->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaTurretRotator = AimAsRotator - TurretRotator;
	auto DeltaCabinRotator = AimAsRotator - CabRotator;
	if (DeltaCabinRotator.Yaw > 200.0f) DeltaCabinRotator.Yaw = DeltaCabinRotator.Yaw - 360.0f;	// fix rotation positive
	if (DeltaCabinRotator.Yaw < -200.0f) DeltaCabinRotator.Yaw = DeltaCabinRotator.Yaw + 360.0f; // fix rotation negative
	//UE_LOG(LogTemp, Warning, TEXT("AimAsRotator YAW: %f (orig: %f) + CAB: %f + delta = %f"), AimAsRotator.Yaw, AimDirection.Rotation().Yaw, CabRotator.Yaw, DeltaCabinRotator.Yaw);
	
	UMechAimingComponent::GunTurret->Elevate(DeltaTurretRotator.Pitch);
	UMechAimingComponent::MechCabin->LookRotate(DeltaCabinRotator.Yaw);
}
