// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include <SimpleFPS/SimpleFPSCharacter.h>
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>
#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SimpleFPSHUD.generated.h"

UCLASS()
class ASimpleFPSHUD : public AHUD
{
	GENERATED_BODY()

public:
	ASimpleFPSHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Font)
		UFont* ammoFont; //added

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

