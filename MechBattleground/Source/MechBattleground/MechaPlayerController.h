// ÷опирайт

#pragma once

#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"
#include "EngineGlobals.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MechaPlayerController.generated.h"

class UMechAimingComponent;

/**
 * Responsible to helping player aim
 */
UCLASS()
class MECHBATTLEGROUND_API AMechaPlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FindAimingComponent(UMechAimingComponent* MechAimRef);

public:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// crosshair screen position (relative)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GUI")
	float CrosshairScreenXLocation = 0.5f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GUI")
	float CrosshairScreenYLocation = 0.25f;
	// visible distance
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot")
	float LineTraceRange = 1000000.0f;
	
private:
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& OutLookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;
};
