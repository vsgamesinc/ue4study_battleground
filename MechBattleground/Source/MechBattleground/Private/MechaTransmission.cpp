// Fill out your copyright notice in the Description page of Project Settings.

#include "MechaTransmission.h"

void UMechaTransmission::SetVelocity(float Direction)
{
	UE_LOG(LogTemp, Warning, TEXT("UMechaTransmission::SetVelocity: %f"), Direction);

	// TODO clamp Direction
	auto ForceApplied = GetForwardVector() * Direction * MaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto mechaRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	mechaRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}


