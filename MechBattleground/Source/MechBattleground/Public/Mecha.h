// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "CoreMinimal.h"
#include "Mecha.generated.h"

UCLASS()
class MECHBATTLEGROUND_API AMecha : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMecha();

	void AimAt(FVector HitLocation);

private:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
