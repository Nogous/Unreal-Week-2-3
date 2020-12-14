// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Options_SaveGame.h"

#include "RPG_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API URPG_GameInstance : public UGameInstance
{
	GENERATED_BODY()
	

public:

	virtual void Init() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
		UOptions_SaveGame* options;

	UFUNCTION(Blueprintable)
	void SaveGameOptions();
	UFUNCTION(Blueprintable)
	void LoadGameOptions();
};
