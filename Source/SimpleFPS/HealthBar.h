// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StationaryEnemy.h"
#include "HealthBar.generated.h"

UCLASS( Abstract )
class SIMPLEFPS_API UHealthBar : public UUserWidget
{
	GENERATED_BODY()

public:
	void setEnemy(AStationaryEnemy* e);
	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	TWeakObjectPtr<AStationaryEnemy> enemy;


	UPROPERTY(meta = (BindWidget))
		class UProgressBar* HealthBar;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* CurrentHealthLabel;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* MaxHealthLabel;
};
