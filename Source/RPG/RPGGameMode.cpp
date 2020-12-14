// Copyright Epic Games, Inc. All Rights Reserved.

#include "RPGGameMode.h"
#include "RPGCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARPGGameMode::ARPGGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ARPGGameMode::OnPlayerDestroyed(AController* controller, FVector spawnPosition, FRotator spawnRotation)
{
	if (GEngine) {
		//GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("call death"));
	}
	_controller = controller;
	_spawnPosition = spawnPosition;
	_spawnRotation = spawnRotation;
	GetWorld()->GetTimerManager().SetTimer(_loopTimerHandle, this, &ARPGGameMode::SpawnNewPlayer, 1.f, false);
}

// respawn after delay
void ARPGGameMode::SpawnNewPlayer()
{
	APawn* pawn = GetWorld()->SpawnActor<APawn>(DefaultPawnClass, _spawnPosition, _spawnRotation);
	if (pawn)
	{
		if (GEngine) {
			//GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("controller ok"));
		}
		if (_controller)
			_controller->Possess(pawn);
	}
}
