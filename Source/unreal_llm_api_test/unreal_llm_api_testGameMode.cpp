// Copyright Epic Games, Inc. All Rights Reserved.

#include "unreal_llm_api_testGameMode.h"
#include "unreal_llm_api_testCharacter.h"
#include "UObject/ConstructorHelpers.h"

Aunreal_llm_api_testGameMode::Aunreal_llm_api_testGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
