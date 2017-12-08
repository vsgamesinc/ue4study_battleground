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
	UFUNCTION(BlueprintCallable, category = "Input")
	void SetMotionRotation(float RotationDirection);
	UFUNCTION(BlueprintCallable, category = "Input")
	void SetMotionJump(float Direction);
	
	// Maximum Mecha Transmission driving force in Newtons
	UPROPERTY(EditDefaultsOnly, category = "Drive")
	float MaxDrivingForce = 50000000.0f;
	// Maximum Mecha Transmission JumpJet force in Newtons
	UPROPERTY(EditDefaultsOnly, category = "Drive")
	float MaxJumpingForce = 50000000.0f;
	// Degreese to rotation
	UPROPERTY(EditDefaultsOnly, category = "Drive")
	float MaxRotationSpeed = 30.0f;
	
};
