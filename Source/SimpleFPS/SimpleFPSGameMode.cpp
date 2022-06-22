// Copyright Epic Games, Inc. All Rights Reserved.

#include "SimpleFPSGameMode.h"
#include "SimpleFPSHUD.h"
#include "SimpleFPSCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASimpleFPSGameMode::ASimpleFPSGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ASimpleFPSHUD::StaticClass();
}
