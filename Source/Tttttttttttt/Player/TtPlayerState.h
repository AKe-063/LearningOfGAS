// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Abilities/GameplayAbility.h"
#include "TtPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class TTTTTTTTTTTT_API ATtPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	ATtPlayerState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	// The ability system component sub-object used by player characters.
	UPROPERTY(VisibleAnywhere, Category = "Tt|PlayerState")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
};
