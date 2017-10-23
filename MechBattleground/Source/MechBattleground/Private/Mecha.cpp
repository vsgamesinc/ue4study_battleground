// Fill out your copyright notice in the Description page of Project Settings.

#include "Mecha.h"


// Sets default values
AMecha::AMecha()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMecha::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMecha::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMecha::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

