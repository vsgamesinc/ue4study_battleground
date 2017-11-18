// Fill out your copyright notice in the Description page of Project Settings.

#include "MechAIController.h"
#include "Mecha.h"

AMecha* AMechAIController::GetControlledMecha() const
{
	return Cast<AMecha>(GetPawn());
}

AMecha* AMechAIController::GetPlayerMecha() const
{
	auto playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!playerPawn) { return nullptr; }
	return Cast<AMecha>(playerPawn);
}

void AMechAIController::BeginPlay()
{
	Super::BeginPlay();

	AMechAIController::MechaUnderControl = AMechAIController::GetControlledMecha();
	if (AMechAIController::MechaUnderControl != nullptr)
	{
		//UE_LOG(LogTemp, Error, TEXT("AMechAIController: Enemy %s has been possessed by AI"), *(AMechAIController::MechaUnderControl->GetName()));
	}

	AMecha* playerMecha = AMechAIController::GetPlayerMecha();
	if (playerMecha)
	{
		//UE_LOG(LogTemp, Warning, TEXT("AMechAIController: Detected enemy mecha: %s"), *(playerMecha->GetName()));
	}
}

void AMechAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (AMechAIController::MechaUnderControl != nullptr)
	{
		AMechAIController::MechaUnderControl->AimAt(AMechAIController::GetPlayerMecha()->GetActorLocation());
	}
}
