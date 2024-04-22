#pragma once

#include "AbilitySystemComponent.h"
#include "TtAttributeBaseSet.h"
#include "TtHealthSet.generated.h"

UCLASS()
class TTTTTTTTTTTT_API UTtHealthSet : public UTtAttributeBaseSet
{
	GENERATED_BODY()

public:
	UTtHealthSet();

	ATTRIBUTE_ACCESSORS(UTtHealthSet, Health);
	ATTRIBUTE_ACCESSORS(UTtHealthSet, MaxHealth);

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;
	virtual void PostAttributeBaseChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) const override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Tt|Health", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Health;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Tt|Health", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxHealth;
};
