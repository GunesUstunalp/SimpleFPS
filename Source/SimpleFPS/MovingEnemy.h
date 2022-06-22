// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <SimpleFPS/SimpleFPSCharacter.h>
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingEnemy.generated.h"

UCLASS()
class SIMPLEFPS_API AMovingEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingEnemy();
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* VisualMesh;

	UPROPERTY(VisibleAnywhere)
		int health;

	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "EnemyBehavior")
		int triggerRadius;

	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "EnemyBehavior")
		float distanceToCharacter;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
