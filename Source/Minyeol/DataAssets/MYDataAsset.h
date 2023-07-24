#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MYTypes.h"
#include "MYDataAsset.generated.h"

UCLASS(BlueprintType, Blueprintable)
class MINYEOL_API UMYDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly)
	FCharacterData CharacterData;
};
