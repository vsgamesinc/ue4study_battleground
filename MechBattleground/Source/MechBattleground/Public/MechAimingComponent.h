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

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MECHBATTLEGROUND_API UMechAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Init(UMechCabin* cabinToSet, UStaticMeshComponent* gunTurretBarrelToSet, UMechTurret* gunTurretToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Shoot")
	EFiringState FiringState = EFiringState::Reloading;

private:
	// Sets default values for this component's properties
	UMechAimingComponent();

	UMechTurret* GunTurret = nullptr;
	UStaticMeshComponent* GunTurretBarrel = nullptr;
	UMechCabin* MechCabin = nullptr;

	void moveTurret(FVector AimDirection);
	
};