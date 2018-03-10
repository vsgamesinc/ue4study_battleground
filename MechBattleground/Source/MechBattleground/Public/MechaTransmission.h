// ÷опирайты

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
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetVelocity(float Direction);
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetMotionRotation(float RotationDirection);
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetMotionJump(float Direction);
	
	// Maximum Mecha Transmission driving force in Newtons
	UPROPERTY(EditDefaultsOnly, Category = "Drive")
	float MaxDrivingForce = 50000000.0f;
	// Maximum Mecha Transmission JumpJet force in Newtons
	UPROPERTY(EditDefaultsOnly, Category = "Drive")
	float MaxJumpingForce = 50000000.0f;
	// Degreese to rotation
	UPROPERTY(EditDefaultsOnly, Category = "Drive")
	float MaxRotationSpeed = 30.0f;
	
};
