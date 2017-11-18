// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "MechAimingComponent.generated.h"

class UMechTurret; //Forward declaration

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MECHBATTLEGROUND_API UMechAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMechAimingComponent();

private:
	UMechTurret* GunTurret = nullptr;
	UStaticMeshComponent* GunTurretBarrel = nullptr;

	void moveTurret(FVector AimDirection);

public:	
	void AimAt(FVector HitLocation, float LaunchSpeed);

	void SetTurretGunReference(UMechTurret* GunToSet);
	void SetTurretBarrelReference(UStaticMeshComponent* GunToSet);
	
};