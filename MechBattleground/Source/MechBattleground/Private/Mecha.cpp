// Fill out your copyright notice in the Description page of Project Settings.

#include "Mecha.h"
#include "MechCabin.h"
#include "MechAimingComponent.h"
#include "Projectile.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"


// Sets default values
AMecha::AMecha()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false; 

	MechAimingComponent = CreateDefaultSubobject<UMechAimingComponent>(FName("Aiming Component"));

	//MechAimingComponent = CreateDefaultSubobject<UMechAimingComponent>(FName("Aiming Component"));
}

void AMecha::SetTurretReference(UMechTurret* TurretToSet)
{
	if (!MechAimingComponent) return;
	
	MechAimingComponent->SetTurretGunReference(TurretToSet);
}

void AMecha::SetTurretBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	if (!MechAimingComponent) return;

	MechAimingComponent->SetTurretBarrelReference(BarrelToSet);

	AMecha::TurretBarrel = BarrelToSet;
}

void AMecha::SetMechCabinReference(UMechCabin* CabToSet)
{
	if (!CabToSet) return;

	MechAimingComponent->SetMechCabinReference(CabToSet);
}


// Called when the game starts or when spawned
void AMecha::BeginPlay()
{
	Super::BeginPlay();
	//UE_LOG(LogTemp, Error, TEXT("AMecha::BeginPlay()"));
}

// Called to bind functionality to input
void AMecha::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

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

