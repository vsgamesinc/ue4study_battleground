// Fill out your copyright notice in the Description page of Project Settings.

#include "MechAIController.h"
#include "Mecha.h"


void AMechAIController::BeginPlay()
{
	Super::BeginPlay();
}

void AMechAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto playerMecha = Cast<AMecha>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto thisMecha = Cast<AMecha>(GetPawn());
	
	if (playerMecha)
	{
		thisMecha->AimAt(playerMecha->GetActorLocation());
		thisMecha->FireMainWeapon(); //TODO scale bot fire time
	}
}
