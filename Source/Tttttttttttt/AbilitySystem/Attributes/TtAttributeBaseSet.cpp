#include "TtAttributeBaseSet.h"

#include "AbilitySystem/TtAbilitySystemComponent.h"

UTtAttributeBaseSet::UTtAttributeBaseSet()
{
}

UWorld* UTtAttributeBaseSet::GetWorld() const
{
	const UObject* Outer = GetOuter();
	check(Outer);

	return Outer->GetWorld();
}

UTtAbilitySystemComponent* UTtAttributeBaseSet::GetTtAbilitySystemComponent() const
{
	return Cast<UTtAbilitySystemComponent>(GetOwningAbilitySystemComponent());
}
