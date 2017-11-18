// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "MechTurret.generated.h"

/**
 * Mecha Turret with ctrls
 */
UCLASS(ClassGroup = (MechaFragments), meta = (BlueprintSpawnableComponent))
class MECHBATTLEGROUND_API UMechTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float DegPerSec);
	
private:
	// Speed of Mecha's Turret Aiming (deg per sec)
	UPROPERTY(EditAnywhere, Category = Setup)
	float AimingSpeed = 20;

	// Speed of Mecha's Turret Aiming (deg per sec)
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevation = 30;
	// Speed of Mecha's Turret Aiming (deg per sec)
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevation = -30;
};
