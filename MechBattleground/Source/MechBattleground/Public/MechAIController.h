// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MechaPlayerController.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/GameFramework/Controller.h"
#include "AIController.h"
#include "MechAIController.generated.h"

class AMecha;
/**
 * 
 */
UCLASS()
class MECHBATTLEGROUND_API AMechAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	//AMecha* GetControlledMecha() const;
	//AMecha* GetPlayerMecha() const;

	// radius for Mecha moving perception
	UPROPERTY(EditAnywhere, Category = "AI Controller")
	float mechaAcceptanceRadius = 3000.0f;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	//AMecha* MechaUnderControl = nullptr;
	
};
