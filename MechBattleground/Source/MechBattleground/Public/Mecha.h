// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MechAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "CoreMinimal.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectGlobals.h"
#include "Mecha.generated.h"

class UMechTurret;

UCLASS()
class MECHBATTLEGROUND_API AMecha : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UMechTurret* TurretToSet);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretBarrelReference(UStaticMeshComponent* BarrelToSet);

	UPROPERTY(EditAnywhere, Category = Shooting)
	float turretShootSpeed = 100000;

protected:
	UMechAimingComponent* MechAimingComponent = nullptr;

private:
	// Called when the game starts or when spawned
	AMecha();

	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
