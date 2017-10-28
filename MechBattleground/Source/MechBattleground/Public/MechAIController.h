// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Mecha.h"
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
	
public:
	AMecha* GetControlledMecha() const;

	virtual void BeginPlay() override;

private:
	AMecha* MechaUnderControl = nullptr;
	
	
};
