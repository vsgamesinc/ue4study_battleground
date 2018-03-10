// ÷опирайты

#pragma once

#include "GameFramework/Pawn.h"
#include "CoreMinimal.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectGlobals.h"
#include "Mecha.generated.h"

UCLASS()
class MECHBATTLEGROUND_API AMecha : public APawn
{
	GENERATED_BODY()

private:
	// Called when the game starts or when spawned
	AMecha();

	virtual void BeginPlay() override;
};