// ÷опирайты

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "MechAimingComponent.generated.h"

UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};

class UMechTurret; //Forward declaration
class UMechCabin;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MECHBATTLEGROUND_API UMechAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Init(UMechCabin* cabinToSet, UStaticMeshComponent* gunTurretBarrelToSet, UMechTurret* gunTurretToSet);

	void AimAt(FVector HitLocation);

	// Sets default values for this pawn's properties
	UFUNCTION(BlueprintCallable, Category = "Shooting")
	void FireMainWeapon();
	UFUNCTION(BlueprintCallable, Category = "Shooting")
	void FireAltWeapon();

	UPROPERTY(EditAnywhere, Category = "Shooting")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	// Main Weapon reload time in seconds
	UPROPERTY(EditDefaultsOnly, Category = "Shooting")
	float turretReloadTime = 3;

	UPROPERTY(EditAnywhere, Category = "Shooting")
	float turretShootSpeed = 100000;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Shoot")
	EFiringState FiringState = EFiringState::Locked;

private:
	// Sets default values for this component's properties
	UMechAimingComponent();

	UMechTurret* GunTurret = nullptr;
	UStaticMeshComponent* GunTurretBarrel = nullptr;
	UMechCabin* MechCabin = nullptr;

	double LastFireTime = 0;

	void moveTurret(FVector AimDirection);
	
};