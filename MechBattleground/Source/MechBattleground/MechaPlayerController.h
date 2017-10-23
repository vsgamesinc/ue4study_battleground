// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Mecha.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MechaPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MECHBATTLEGROUND_API AMechaPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
		AMecha* GetControlledMecha() const;
	

};
