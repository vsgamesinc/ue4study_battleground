// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Mecha.h"
#include "MechaPlayerController.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/GameFramework/Controller.h"
#include "AIController.h"
#include "MechAIController.generated.h"

/**
 * 
 */
UCLASS()
class MECHBATTLEGROUND_API AMechAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	AMecha* GetControlledMecha() const;
	AMecha* GetPlayerMecha() const;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	AMecha* MechaUnderControl = nullptr;
	
};
