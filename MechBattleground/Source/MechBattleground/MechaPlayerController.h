// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"
#include "EngineGlobals.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MechaPlayerController.generated.h"

class AMecha;

/**
 * 
 */
UCLASS()
class MECHBATTLEGROUND_API AMechaPlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	AMecha * GetControlledMecha() const;

public:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// crosshair screen position (relative)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=GUI_Params)
	float CrosshairScreenXLocation = 0.5f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GUI_Params)
	float CrosshairScreenYLocation = 0.25f;
	// visible distance
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shooting_Params)
	float LineTraceRange = 1000000.0f;
	
private:
	AMecha* MechaUnderControl = nullptr;

	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& OutLookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;
};
