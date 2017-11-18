// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "MechCabin.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (MechaFragments), meta = (BlueprintSpawnableComponent))
class MECHBATTLEGROUND_API UMechCabin : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void LookRotate(float RelativeSpeed);
	
private:
	// Speed of Mecha's Cabin Aiming (deg per sec)
	UPROPERTY(EditAnywhere, Category = Setup)
	float AimingSpeed = 50;

	// Limit of Mecha's Cabin Aiming (max)
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxRotation = 90;
	// Limit of Mecha's Cabin Aiming (min)
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinRotation = -90;
	
};
