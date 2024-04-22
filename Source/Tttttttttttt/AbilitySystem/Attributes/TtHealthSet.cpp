#include "TtHealthSet.h"

#include "AbilitySystemLog.h"

UTtHealthSet::UTtHealthSet()
{
}

void UTtHealthSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	UE_LOG(LogAbilitySystem, Warning, TEXT("PreAttributeChange: [%s] : [%f]"), *Attribute.AttributeName, NewValue);
}

void UTtHealthSet::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	Super::PreAttributeBaseChange(Attribute, NewValue);

	UE_LOG(LogAbilitySystem, Warning, TEXT("PreAttributeBaseChange: [%s] : [%f]"), *Attribute.AttributeName, NewValue);
}

void UTtHealthSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	Super::PostAttributeChange(Attribute, OldValue, NewValue);

	UE_LOG(LogAbilitySystem, Warning, TEXT("PostAttributeChange: [%s] : [%f]  [%f]"), *Attribute.AttributeName, OldValue, NewValue);
}

void UTtHealthSet::PostAttributeBaseChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) const
{
	Super::PostAttributeBaseChange(Attribute, OldValue, NewValue);

	UE_LOG(LogAbilitySystem, Warning, TEXT("PostAttributeBaseChange: [%s] : [%f]  [%f]"), *Attribute.AttributeName, OldValue, NewValue);
}
