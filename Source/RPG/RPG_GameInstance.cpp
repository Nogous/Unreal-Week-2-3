// Fill out your copyright notice in the Description page of Project Settings.


#include "Kismet/GameplayStatics.h"
#include "Options_SaveGame.h"

#include "RPG_GameInstance.h"

void URPG_GameInstance::Init() {
	UGameInstance::Init();
	LoadGameOptions();
}

#pragma region Save/Load

void URPG_GameInstance::SaveGameOptions() {
	UOptions_SaveGame* SaveGameInstance = Cast<UOptions_SaveGame>(UGameplayStatics::CreateSaveGameObject(UOptions_SaveGame::StaticClass()));

	//SaveGameInstance->PlayerLocation = this->GetActorLocation();

	UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("Option"), 0);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Game Saved."));
}

void URPG_GameInstance::LoadGameOptions() {
	UOptions_SaveGame* SaveGameInstance = Cast<UOptions_SaveGame>(UGameplayStatics::CreateSaveGameObject(UOptions_SaveGame::StaticClass()));

	SaveGameInstance = Cast<UOptions_SaveGame>(UGameplayStatics::LoadGameFromSlot("Option", 0));

	//this->SetActorLocation(SaveGameInstance->PlayerLocation);
	options->Resolution = SaveGameInstance->Resolution; //(SaveGameInstance->Resolution);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Game Loaded."));
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString(SaveGameInstance->Resolution));
}

#pragma endregion