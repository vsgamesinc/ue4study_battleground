// Fill out your copyright notice in the Description page of Project Settings.

#include "MechaNavMovementComponent.h"
#include "MechaTransmission.h"

void UMechaNavMovementComponent::Init(UMechaTransmission* transmissionToSet)
{
	MechaTransmission = transmissionToSet;
}

void UMechaNavMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	float IntendMoveForwardValue = FVector::DotProduct(TankForward, AIForwardIntention);
	float IntendTurnRightValue = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	// TODO Fix air freezing
	//IntendMoveForward(IntendMoveForwardValue);
	//IntendTurnRight(IntendTurnRightValue);
}

void UMechaNavMovementComponent::IntendMoveForward(float Throw)
{
	if (!ensure(MechaTransmission)) { return; }
	MechaTransmission->SetVelocity(Throw);
}

void UMechaNavMovementComponent::IntendTurnRight(float Throw)
{
	if (!ensure(MechaTransmission)) { return; }
	MechaTransmission->SetMotionRotation(Throw);
}

