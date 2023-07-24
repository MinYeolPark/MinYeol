#include "MYAttributeSetBase.h"

#include "GameplayEffectExtension.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Net/UnrealNetwork.h"

bool UMYAttributeSetBase::PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data)
{
	Super::PreGameplayEffectExecute(Data);
		
	UE_LOG(LogTemp, Warning, TEXT("Pre"));
	return true;
}

void UMYAttributeSetBase::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));		
	}
	else if (Data.EvaluatedData.Attribute == GetMaxMovementSpeedAttribute())
	{
		ACharacter* OwningCharacter = Cast<ACharacter>(GetOwningActor());
		UCharacterMovementComponent* CharacterMovement = OwningCharacter ? OwningCharacter->GetCharacterMovement() : nullptr;
		const float MaxSpeed = GetMaxMovementSpeed();

		if (CharacterMovement)
		{
			CharacterMovement->MaxWalkSpeed = MaxSpeed;
		}
	}
}

void UMYAttributeSetBase::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	UE_LOG(LogTemp, Warning, TEXT("Onrep_Health"));
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMYAttributeSetBase, Health, OldHealth);
}

void UMYAttributeSetBase::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	UE_LOG(LogTemp, Warning, TEXT("Onrep_MaxHealth"));
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMYAttributeSetBase, MaxHealth, OldMaxHealth);
}

void UMYAttributeSetBase::OnRep_Stamina(const FGameplayAttributeData& OldStamina)
{
	UE_LOG(LogTemp, Warning, TEXT("Onrep_Stamina"));
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMYAttributeSetBase, Stamina, OldStamina);
}

void UMYAttributeSetBase::OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina)
{
	UE_LOG(LogTemp, Warning, TEXT("Onrep_MaxStamina"));
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMYAttributeSetBase, MaxStamina, OldMaxStamina);
}

void UMYAttributeSetBase::OnRep_MaxMovementSpeed(const FGameplayAttributeData& OldMaxMovementSpeed)
{
	UE_LOG(LogTemp, Warning, TEXT("Onrep_MaxMovementSpeed"));
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMYAttributeSetBase, MaxMovementSpeed, OldMaxMovementSpeed);
}

void UMYAttributeSetBase::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	UE_LOG(LogTemp, Warning, TEXT("Replicated Props"));
	DOREPLIFETIME_CONDITION_NOTIFY(UMYAttributeSetBase, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMYAttributeSetBase, MaxHealth, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UMYAttributeSetBase, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMYAttributeSetBase, MaxStamina, COND_None, REPNOTIFY_Always);
		
	DOREPLIFETIME_CONDITION_NOTIFY(UMYAttributeSetBase, MaxMovementSpeed, COND_None, REPNOTIFY_Always);
}