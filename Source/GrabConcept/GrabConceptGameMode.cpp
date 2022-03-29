// Copyright Epic Games, Inc. All Rights Reserved.

#include "GrabConceptGameMode.h"
#include "GrabConceptHUD.h"
#include "GrabConceptCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGrabConceptGameMode::AGrabConceptGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AGrabConceptHUD::StaticClass();
}
