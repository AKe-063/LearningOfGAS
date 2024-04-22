#pragma once

#include "AttributeSet.h"
#include "TtAttributeBaseSet.generated.h"

class UTtAbilitySystemComponent;

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class TTTTTTTTTTTT_API UTtAttributeBaseSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UTtAttributeBaseSet();

	UWorld* GetWorld() const override;

	UTtAbilitySystemComponent* GetTtAbilitySystemComponent() const;
};
