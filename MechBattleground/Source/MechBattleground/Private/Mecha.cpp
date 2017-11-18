// Fill out your copyright notice in the Description page of Project Settings.

#include "Mecha.h"


// Sets default values
AMecha::AMecha()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true; 

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


// Called when the game starts or when spawned
void AMecha::BeginPlay()
{
	Super::BeginPlay();
	//UE_LOG(LogTemp, Error, TEXT("AMecha::BeginPlay()"));
}

// Called every frame
void AMecha::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMecha::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMecha::AimAt(FVector HitLocation)
{
	MechAimingComponent->AimAt(HitLocation, AMecha::turretShootSpeed);
}

