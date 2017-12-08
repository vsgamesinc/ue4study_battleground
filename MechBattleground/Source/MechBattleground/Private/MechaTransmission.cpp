// Fill out your copyright notice in the Description page of Project Settings.

#include "MechaTransmission.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void UMechaTransmission::SetVelocity(float Direction)
{
	//UE_LOG(LogTemp, Warning, TEXT("UMechaTransmission::SetVelocity: %f"), InputDirection);

	// TODO clamp Direction
	auto ForceApplied = GetForwardVector() * Direction * UMechaTransmission::MaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto mechaRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	mechaRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

void UMechaTransmission::SetMotionJump(float Direction)
{
	UE_LOG(LogTemp, Warning, TEXT("UMechaTransmission::SetMotionJump: %f"), Direction);
	if (Direction > 0)
	{
		auto ForceApplied = GetUpVector() * Direction * UMechaTransmission::MaxJumpingForce;
		auto ForceLocation = GetComponentLocation();
		auto mechaRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
		mechaRoot->AddForceAtLocation(ForceApplied, ForceLocation);
	}
}

void UMechaTransmission::SetMotionRotation(float RotationDirection)
{
	//UE_LOG(LogTemp, Warning, TEXT("UMechaTransmission::SetMotionRotation: %f"), RotationDirection);
	RotationDirection = FMath::Clamp<float>(RotationDirection, -1, 1);
	auto RotationChange = RotationDirection * UMechaTransmission::MaxRotationSpeed * GetWorld()->DeltaTimeSeconds;
	//auto RawNewRotation = RelativeRotation.Yaw + RotationChange;
	auto mechaRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	UE_LOG(LogTemp, Warning, TEXT("UMechaTransmission::SetMotionRotation(%f): %f"), RotationChange, mechaRoot->RelativeRotation.Yaw);
	auto RawNewRotation = mechaRoot->RelativeRotation.Yaw + RotationChange;
	mechaRoot->SetRelativeRotation(FRotator(0, RawNewRotation, 0));
	//SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}
