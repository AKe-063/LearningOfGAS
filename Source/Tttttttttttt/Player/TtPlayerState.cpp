// Fill out your copyright notice in the Description page of Project Settings.


#include "TtPlayerState.h"

#include "AbilitySystemLog.h"
#include "AbilitySystem/TtAbilitySystemComponent.h"
#include "Character/TtPawnData.h"


ATtPlayerState::ATtPlayerState(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	AbilitySystemComponent = ObjectInitializer.CreateDefaultSubobject<UTtAbilitySystemComponent>(this, TEXT("AbilitySystemComponent"));
	HealthSet = ObjectInitializer.CreateDefaultSubobject<UTtHealthSet>(this, TEXT("AttributeSet"));
}

UAbilitySystemComponent* ATtPlayerState::GetAbilitySystemComponent() const
{
	return GetTtAbilitySystemComponent();
}

void ATtPlayerState::BeginPlay()
{
	Super::BeginPlay();

	if (AbilitySystemComponent)
	{
		if (PreloadedAbilities.Num() > 0)
		{
			for (auto PreloadedAbility : PreloadedAbilities)
			{
				if (PreloadedAbility != nullptr)
				{
					AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(PreloadedAbility.GetDefaultObject(), 1));
				}
			}
		}
	}

	// 初始化 ASC
	AbilitySystemComponent->InitAbilityActorInfo(this, this->GetPawn());
	InitPlayerPawnAttributes();

	// 注册 Attribute 变化事件
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UTtHealthSet::GetHealthAttribute()).AddUObject(this, &ATtPlayerState::OnHealthChanged);
}

void ATtPlayerState::OnHealthChanged(const FOnAttributeChangeData& Data)
{
	UE_LOG(LogAbilitySystem, Warning, TEXT("OnHealthChanged: [%s] : [%f]  [%f]"), *Data.Attribute.AttributeName, Data.OldValue, Data.NewValue);
}

void ATtPlayerState::GiveAbility(TSubclassOf<UGameplayAbility> Ability, int32 Level)
{
	if (AbilitySystemComponent)
	{
		if (HasAuthority() && Ability)
		{
			AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(Ability, Level));
		}
		AbilitySystemComponent->InitAbilityActorInfo(this, this->GetPawn());
	}
}

void ATtPlayerState::InitPlayerPawnAttributes()
{
	check(PawnData);

	HealthSet->InitHealth(PawnData->Health);
	HealthSet->InitMaxHealth(PawnData->MaxHealth);
}
