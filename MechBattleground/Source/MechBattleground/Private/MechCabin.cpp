// Fill out your copyright notice in the Description page of Project Settings.

#include "MechCabin.h"

void UMechCabin::LookRotate(float RelativeSpeed)
{
	//UE_LOG(LogTemp, Warning, TEXT("RelativeSpeed = %f"), RelativeSpeed);
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = RelativeSpeed * UMechCabin::AimingSpeed * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;
	//RawNewRotation = FMath::Clamp<float>(RawNewRotation, UMechCabin::MinRotation, UMechCabin::MaxRotation);
	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}


