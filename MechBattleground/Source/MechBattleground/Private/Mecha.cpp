// ÷опирайты

#include "Mecha.h"
#include "MechCabin.h"
#include "MechTurret.h"
#include "MechAimingComponent.h"
#include "MechaNavMovementComponent.h"
#include "Projectile.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"


// Sets default values
AMecha::AMecha()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void AMecha::FireMainWeapon()
{
	bool isReloaded = (FPlatformTime::Seconds() - AMecha::LastFireTime) > AMecha::turretReloadTime;

	if (AMecha::TurretBarrel && isReloaded)
	{
		// Spawn projectile at the Socket location on the Turret
		auto projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			AMecha::TurretBarrel->GetSocketLocation(FName("Projectile")),
			AMecha::TurretBarrel->GetSocketRotation(FName("Projectile"))
			);
		projectile->LaunchProjectile(AMecha::turretShootSpeed);
		
		AMecha::LastFireTime = FPlatformTime::Seconds();
	}
}

void AMecha::FireAltWeapon()
{
	UE_LOG(LogTemp, Error, TEXT("AMecha::FireAltWeapon()"));
}

void AMecha::AimAt(FVector HitLocation)
{
	MechAimingComponent->AimAt(HitLocation, AMecha::turretShootSpeed);
}

