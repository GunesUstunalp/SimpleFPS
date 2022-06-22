// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <SimpleFPS/SimpleFPSCharacter.h>
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>
#include "Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MaxAmmoPickup.generated.h"

UCLASS()
class SIMPLEFPS_API AMaxAmmoPickup : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AMaxAmmoPickup();
	UPROPERTY(EditAnywhere, Category = "Ammo")
		int ammoPickupVal; //added

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//ADDED
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ammo", meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* AmmoPickupMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ammo", meta = (AllowPrivateAccess = "true"))
		class UShapeComponent* PickupBox;

	UFUNCTION()
		void OnPickupEvent(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult);

};
