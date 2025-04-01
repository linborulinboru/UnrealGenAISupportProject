// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_ServerHandlePostLogin.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerState.h"
#include "GameFramework/PlayerController.h"

void UBP_ServerHandlePostLogin::HandlePlayerPostLogin(APlayerController* PlayerController)
{
    // 檢查輸入參數是否有效
    if (!PlayerController)
    {
        UE_LOG(LogTemp, Error, TEXT("HandlePlayerPostLogin: PlayerController is invalid"));
        return;
    }

    // 從PlayerController獲取PlayerState
    APlayerState* PlayerState = PlayerController->GetPlayerState<APlayerState>();
    if (!PlayerState)
    {
        UE_LOG(LogTemp, Warning, TEXT("HandlePlayerPostLogin: PlayerState is invalid"));
        return;
    }

    // 獲取玩家名稱和ID
    FString PlayerName = PlayerState->GetPlayerName();
    int32 PlayerId = PlayerState->GetPlayerId();
    
    // 獲取玩家位置
    FVector PlayerLocation = PlayerController->GetPawn() ? PlayerController->GetPawn()->GetActorLocation() : FVector::ZeroVector;
    
    // 處理玩家登錄邏輯
    UE_LOG(LogTemp, Log, TEXT("Player '%s' (ID: %d) logged in at location: X=%.2f, Y=%.2f, Z=%.2f"), 
        *PlayerName, 
        PlayerId,
        PlayerLocation.X,
        PlayerLocation.Y,
        PlayerLocation.Z);
    
    // 在遊戲中顯示登錄訊息
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(
            -1,
            5.0f,
            FColor::Green,
            FString::Printf(TEXT("玩家 '%s' (ID: %d) 已登入系統\n位置: X=%.2f, Y=%.2f, Z=%.2f"), 
                *PlayerName, 
                PlayerId,
                PlayerLocation.X,
                PlayerLocation.Y,
                PlayerLocation.Z)
        );
    }
}




