// Fill out your copyright notice in the Description page of Project Settings.

#include "MechaPlayerController.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text)

AMecha* AMechaPlayerController::GetControlledMecha() const
{
	return Cast<AMecha>(GetPawn());
}

void AMechaPlayerController::BeginPlay()
{
	Super::BeginPlay();
	print(TEXT("Launch Mission. Drop down Scout BattleMech..."));

	UE_LOG(LogTemp, Warning, TEXT("AMechaPlayerController::BeginPlay()"));
	
	AMechaPlayerController::MechaUnderControl = AMechaPlayerController::GetControlledMecha();
	if (!AMechaPlayerController::MechaUnderControl)
	{
		UE_LOG(LogTemp, Error, TEXT("Control over Mecha not possesed"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Got control over Mecha %s"), *(AMechaPlayerController::MechaUnderControl->GetName()));
	}
}
