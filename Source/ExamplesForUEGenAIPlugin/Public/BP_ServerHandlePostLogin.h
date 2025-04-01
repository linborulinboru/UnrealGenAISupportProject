// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameFramework/PlayerController.h"
#include "BP_ServerHandlePostLogin.generated.h"

/**
 * 藍圖函數庫，用於處理玩家登錄後的服務器端邏輯
 */
UCLASS()
class EXAMPLESFORUEGENAIPLUGIN_API UBP_ServerHandlePostLogin : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	/**
	 * 處理玩家登錄後的邏輯
	 * @param PlayerController 剛登錄的玩家控制器
	 */
	UFUNCTION(BlueprintCallable, Category = "Game|Player")
	static void HandlePlayerPostLogin(APlayerController* PlayerController);
};
