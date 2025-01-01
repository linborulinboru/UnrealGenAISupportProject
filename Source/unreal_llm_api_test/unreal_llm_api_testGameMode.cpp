// Copyright Epic Games, Inc. All Rights Reserved.

#include "unreal_llm_api_testGameMode.h"

#include "GenOAIChat.h"
#include "GenSecureKey.h"
#include "UObject/ConstructorHelpers.h"

Aunreal_llm_api_testGameMode::Aunreal_llm_api_testGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}


	// Get the API key from the plugin
	FString ApiKey = UGenSecureKey::GetGenerativeAIApiKey();
	
	// Display the API key if everything is successful
	if (GEngine)
	{
		FString DisplayMessage = FString::Printf(TEXT("Generative AI API Key: %s"), *ApiKey);
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, DisplayMessage);
	}



	// Define chat settings for testing
	FGenChatSettings ChatSettings;
	ChatSettings.Model = TEXT("gpt-4o");
	ChatSettings.MaxTokens = 100;
    
	// Add initial user message
	FGenChatMessage UserMessage;
	UserMessage.Role = TEXT("user");
	UserMessage.Content = TEXT("Hello, AI! How are you?");
	ChatSettings.Messages.Add(UserMessage);

	// Create the chat node and initiate the request
	UGenOAIChat* ChatNode = UGenOAIChat::CallOpenAIChat(this, ChatSettings);
	if (ChatNode)
	{
		ChatNode->Finished.AddDynamic(this, &Aunreal_llm_api_testGameMode::OnChatCompletion);
		ChatNode->Activate();
	}
	else
	{
		// Log if the chat node creation fails
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Failed to create ChatNode"));
		}
	}
}

void Aunreal_llm_api_testGameMode::OnChatCompletion(const FString& ResponseContent, const FString& ErrorMessage, bool bSuccess)
{
	if (bSuccess)
	{
		// Display the AI response if successful
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, FString::Printf(TEXT("AI Response: %s"), *ResponseContent));
		}
	}
	else
	{
		// Display the error message if failed
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("Error: %s"), *ErrorMessage));
		}
	}
}