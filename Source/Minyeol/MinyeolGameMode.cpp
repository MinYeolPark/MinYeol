// Copyright Epic Games, Inc. All Rights Reserved.

#include "MinyeolGameMode.h"
#include "MinyeolCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMinyeolGameMode::AMinyeolGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
