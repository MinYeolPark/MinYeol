#include "AnimInstances/MYAnimInstance.h"

#include "MYCharacter.h"
#include "MYTypes.h"
#include "Animation/AnimSequenceBase.h"
#include "Animation/AnimationAsset.h"
#include "Animation/Blendspace.h"
#include "DataAssets/MYDataAsset.h"
#include "DataAssets/MYCharacterAnimDataAsset.h"

UBlendSpace* UMYAnimInstance::GetLocomotionBlendspace() const
{
    if(AMYCharacter* Character = Cast<AMYCharacter>(GetOwningActor()))
    {
        FCharacterData Data = Character->GetCharacterData();
        if (Data.CharacterAnimDataAsset)
        {
            return Data.CharacterAnimDataAsset->CharacterAnimationData.MovementBlendspace;
        }
    }
    return DefaultCharacterAnimDataAsset ? DefaultCharacterAnimDataAsset->CharacterAnimationData.MovementBlendspace : nullptr;
}

UAnimSequenceBase* UMYAnimInstance::GetIdleAnimation() const
{
    if (AMYCharacter* Character = Cast<AMYCharacter>(GetOwningActor()))
    {
        FCharacterData Data = Character->GetCharacterData();
        if (Data.CharacterAnimDataAsset)
        {
            return Data.CharacterAnimDataAsset->CharacterAnimationData.IdleAnimationAsset;
        }
    }
    return DefaultCharacterAnimDataAsset ? DefaultCharacterAnimDataAsset->CharacterAnimationData.IdleAnimationAsset : nullptr;
}
