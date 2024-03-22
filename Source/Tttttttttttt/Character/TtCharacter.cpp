// Fill out your copyright notice in the Description page of Project Settings.


#include "TtCharacter.h"

// Sets default values
ATtCharacter::ATtCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATtCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATtCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATtCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

