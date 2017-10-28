// Fill out your copyright notice in the Description page of Project Settings.

#include "MechAIController.h"

AMecha* AMechAIController::GetControlledMecha() const
{
	return Cast<AMecha>(GetPawn());
}

void AMechAIController::BeginPlay()
{
	Super::BeginPlay();

	AMechAIController::MechaUnderControl = AMechAIController::GetControlledMecha();
	if (AMechAIController::MechaUnderControl != nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Enemy %s has been possessed by AI"), *(AMechAIController::MechaUnderControl->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AI possessing error - no mecha found..."));
	}
}
