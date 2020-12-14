// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RPGGameMode.generated.h"

UCLASS(minimalapi)
class ARPGGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ARPGGameMode();

	void OnPlayerDestroyed(AController* controller, FVector spawnPosition, FRotator spawnRotation);

	void SpawnNewPlayer();


	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		AController* _controller;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		FVector _spawnPosition;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		FRotator _spawnRotation;

	FTimerHandle _loopTimerHandle;
};



