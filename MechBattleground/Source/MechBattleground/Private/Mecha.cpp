// ÷опирайты

#include "Mecha.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"


// Sets default values
AMecha::AMecha()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void AMecha::BeginPlay()
{
	Super::BeginPlay();
}