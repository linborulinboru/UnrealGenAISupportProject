// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "unreal_llm_api_testGameMode.generated.h"

UCLASS(minimalapi)
class Aunreal_llm_api_testGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	Aunreal_llm_api_testGameMode();
	void OnChatCompletion(const FString& ResponseContent, const FString& ErrorMessage, bool bSuccess);
};



