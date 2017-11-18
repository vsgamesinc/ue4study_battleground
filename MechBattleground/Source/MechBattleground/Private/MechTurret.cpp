// Fill out your copyright notice in the Description page of Project Settings.

#include "MechTurret.h"

void UMechTurret::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.0f, 1.0f);
	auto ElevationChange = RelativeSpeed * UMechTurret::AimingSpeed * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	RawNewElevation = FMath::Clamp<float>(RawNewElevation, UMechTurret::MinElevation, UMechTurret::MaxElevation);
	SetRelativeRotation(FRotator(RawNewElevation, 0, 0));
}


