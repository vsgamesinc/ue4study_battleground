// Fill out your copyright notice in the Description page of Project Settings.

#include "MechaPlayerController.h"

AMecha* AMechaPlayerController::GetControlledMecha() const
{
	return Cast<AMecha>(GetPawn());
}


