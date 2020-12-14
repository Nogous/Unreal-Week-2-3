// Fill out your copyright notice in the Description page of Project Settings.


#include "Options_SaveGame.h"

UOptions_SaveGame::UOptions_SaveGame() {
	PlayerLocation = FVector(0.f, 0.f, 0.f);


	Resolution = "1280x720";
	ShadowQuality = "Medium";
	TextureQuality = "Medium";
	ViewDistance = "Medium";
	EffectsQuality = "Medium";
	Antialiasing = "Medium";
}