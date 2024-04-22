// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Abilities/GameplayAbility.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "Character/TtPawnData.h"
#include "TtPlayerState.generated.h"

class UTtAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class TTTTTTTTTTTT_API ATtPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ATtPlayerState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UTtAbilitySystemComponent* GetTtAbilitySystemComponent() const { return AbilitySystemComponent; }
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void BeginPlay() override;
	void OnHealthChanged(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintCallable, Category="Ability System")
	void GiveAbility(TSubclassOf<UGameplayAbility> Ability, int32 Level = 1);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tt|Abilities")
	TArray<TSubclassOf<class UGameplayAbility>> PreloadedAbilities;

	// The ability system component sub-object used by player characters.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tt|PlayerState")
	TObjectPtr<UTtAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category ="Tt|PawnData")
	TObjectPtr<const UTtPawnData> PawnData;

private:
	void InitPlayerPawnAttributes();

private:
	UPROPERTY()
	TObjectPtr<UTtHealthSet> HealthSet;
};
