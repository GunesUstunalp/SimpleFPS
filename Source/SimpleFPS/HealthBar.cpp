// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthBar.h"
#include <Components/ProgressBar.h>
#include <Components/TextBlock.h>

void UHealthBar::setEnemy(AStationaryEnemy* e)
{
	enemy = e;
}

void UHealthBar::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (!enemy.IsValid())
		return;

	HealthBar->SetPercent(enemy->health / 100.0);

	FNumberFormattingOptions Opts;
	Opts.SetMaximumFractionalDigits(0);
	CurrentHealthLabel->SetText(FText::AsNumber(enemy->health, &Opts));
	MaxHealthLabel->SetText(FText::AsNumber(100, &Opts));
}
