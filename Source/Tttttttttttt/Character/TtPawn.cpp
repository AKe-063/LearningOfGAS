// Fill out your copyright notice in the Description page of Project Settings.


#include "TtPawn.h"

// Sets default values
ATtPawn::ATtPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATtPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATtPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATtPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

