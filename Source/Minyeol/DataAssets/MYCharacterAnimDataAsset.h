#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MYTypes.h"
#include "MYCharacterAnimDataAsset.generated.h"

UCLASS()
class MINYEOL_API UMYCharacterAnimDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly)
	FCharacterAnimData CharacterAnimationData;
};
