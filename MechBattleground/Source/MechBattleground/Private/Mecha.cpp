// Fill out your copyright notice in the Description page of Project Settings.

#include "Mecha.h"
#include "MechCabin.h"
#include "MechAimingComponent.h"


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
	UE_LOG(LogTemp, Error, TEXT("AMecha::FireMainWeapon()"));
}

void AMecha::FireAltWeapon()
{
	UE_LOG(LogTemp, Error, TEXT("AMecha::FireAltWeapon()"));
}

void AMecha::AimAt(FVector HitLocation)
{
	MechAimingComponent->AimAt(HitLocation, AMecha::turretShootSpeed);
}

