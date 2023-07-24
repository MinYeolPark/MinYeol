// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MYGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class MINYEOL_API UMYGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UMYGameInstance(const FObjectInitializer& ObjectInitializer);

	virtual void Init();

	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join(const FString& Address);

	UFUNCTION(Exec)
	void LoadMenu();

public:

private:
	TSubclassOf<class UUserWidget> MenuClass;
};
