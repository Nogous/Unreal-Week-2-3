// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Options_SaveGame.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API UOptions_SaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UOptions_SaveGame();

	UPROPERTY(EditAnywhere)
		FVector PlayerLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Resolution;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ShadowQuality;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString TextureQuality;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ViewDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString EffectsQuality;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Antialiasing;
};
