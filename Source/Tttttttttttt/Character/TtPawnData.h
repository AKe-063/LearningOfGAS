#pragma once

#include "AbilitySystem/Attributes/TtHealthSet.h"
#include "Engine/DataAsset.h"
#include "TtPawnData.generated.h"

UCLASS(BlueprintType, Const, Meta = (DisplayName = "Tt Pawn Data", ShortTooltip = "Data asset used to define a Pawn."))
class TTTTTTTTTTTT_API UTtPawnData: public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tt|Health")
	float Health;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tt|Health")
	float MaxHealth;
};
