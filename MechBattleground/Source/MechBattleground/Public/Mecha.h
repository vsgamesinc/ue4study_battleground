// ÷опирайты

#pragma once

#include "GameFramework/Pawn.h"
#include "CoreMinimal.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectGlobals.h"
#include "Mecha.generated.h"

class UMechTurret;
class UMechCabin;
class UMechAimingComponent;
class UMechaNavMovementComponent;
class AProjectile;

UCLASS()
class MECHBATTLEGROUND_API AMecha : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Shooting")
	void FireMainWeapon();
	UFUNCTION(BlueprintCallable, Category = "Shooting")
	void FireAltWeapon();

	UPROPERTY(EditAnywhere, Category = "Shooting")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditAnywhere, Category = "Shooting")
	float turretShootSpeed = 100000;
	// Main Weapon reload time in seconds
	UPROPERTY(EditDefaultsOnly, Category = "Shooting")
	float turretReloadTime = 3;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Shoot")
	UMechAimingComponent* MechAimingComponent = nullptr;
	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	UMechaNavMovementComponent* MechMovementComponent = nullptr;

private:
	// Called when the game starts or when spawned
	AMecha();

	// pointer to barrel to generate projectile
	UMechTurret* TurretBarrel = nullptr; // TODO Remove
	
	double LastFireTime = 0;
};
