#include "MYGameInstance.h"

#include "Blueprint/UserWidget.h"

#include "AbilitySystemGlobals.h"

UMYGameInstance::UMYGameInstance(const FObjectInitializer& ObjectInitializer)
{
}

void UMYGameInstance::Init()
{
	UAbilitySystemGlobals::Get().InitGlobalData();
}

void UMYGameInstance::Host()
{
	UEngine* Engine = GetEngine();

	if (ensure(Engine == nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, TEXT("Hosting"));

	UWorld* World = GetWorld();

	if (ensure(Engine == nullptr))return;

	//Hosting하고 listen서버로 설정
	World->ServerTravel("/Game/ThirdPerson/Maps/ThirdPersonMap?listen");
}

void UMYGameInstance::Join(const FString& Address)
{
	UEngine* Engine = GetEngine();

	if (ensure(Engine == nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (ensure(PlayerController == nullptr))return;

	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}

void UMYGameInstance::LoadMenu()
{
	if (ensure(MenuClass != nullptr))return;

	UUserWidget* Menu = CreateWidget<UUserWidget>(this, MenuClass);
	if (ensure(MenuClass != nullptr)) return;
	Menu->AddToViewport();
}
