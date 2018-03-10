// ÷опирайты

#include "MechAIController.h"
#include "MechAimingComponent.h"


void AMechAIController::BeginPlay()
{
	Super::BeginPlay();
}

void AMechAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto playerMecha = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto botMecha = GetPawn();
	if (!ensure(playerMecha && botMecha)) { return; }

	MoveToActor(playerMecha,
				mechaAcceptanceRadius
	);
	
	auto aimComponent = botMecha->FindComponentByClass<UMechAimingComponent>();
	aimComponent->AimAt(playerMecha->GetActorLocation());
	aimComponent->FireMainWeapon(); //TODO scale bot fire time
}
