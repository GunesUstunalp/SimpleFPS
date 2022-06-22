// Copyright Epic Games, Inc. All Rights Reserved.

#include "SimpleFPSHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "UObject/ConstructorHelpers.h"

ASimpleFPSHUD::ASimpleFPSHUD()
{
	// Set the crosshair texture
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("/Game/FirstPerson/Textures/FirstPersonCrosshair"));
	CrosshairTex = CrosshairTexObj.Object;
	
	if(GEngine)
		ammoFont = GEngine->GetMediumFont();
}


void ASimpleFPSHUD::DrawHUD()
{
	Super::DrawHUD();

	// Draw very simple crosshair

	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);
	const FVector2D Corner(Canvas->ClipX * 0.8f, Canvas->ClipY * 0.1f); //added

	// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
	const FVector2D CrosshairDrawPosition( (Center.X),
										   (Center.Y + 20.0f));

	// draw the crosshair
	FCanvasTileItem TileItem( CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem( TileItem );

	//ADDED
	
	ASimpleFPSCharacter* myProjectCharacter = Cast<ASimpleFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	FString ammoText = FString::Printf(TEXT("Ammo: %02d/%02d"), myProjectCharacter->currentAmmo, myProjectCharacter->maxAmmo);
	Canvas->SetDrawColor(FColor::Red);
	Canvas->DrawText(ammoFont, ammoText, Corner.X - 20, Corner.Y, 2.0f, 2.0f);
}
