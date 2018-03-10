// ÷опирайты

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "MechaNavMovementComponent.generated.h"

class UMechaTransmission;

/**
 * Responsible from mecha transmission (legs system)
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MECHBATTLEGROUND_API UMechaNavMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Init(UMechaTransmission* transmissionToSet);
	
	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendMoveForward(float Throw);
	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendTurnRight(float Throw);

	
private:
	UMechaTransmission* MechaTransmission = nullptr;

	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
};
