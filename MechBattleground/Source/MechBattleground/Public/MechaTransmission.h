// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "MechaTransmission.generated.h"

/**
 * Mecha transmission - component for animated mechanical legs & base platform
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class MECHBATTLEGROUND_API UMechaTransmission : public USkeletalMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, category = "Input")
	void SetVelocity(float Direction);
	
	// Maximum Mecha Transmission driving force in Newtons
	UPROPERTY(EditDefaultsOnly)
	float MaxDrivingForce = 500000.0f;	// Force to 50 tonn Mecha with 1g acceleration
	
};
