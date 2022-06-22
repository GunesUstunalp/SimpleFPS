// Copyright Epic Games, Inc. All Rights Reserved.

#include "StationaryEnemy.h"
#include "MovingEnemy.h"
#include "SimpleFPSProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Math/UnrealMathUtility.h"

ASimpleFPSProjectile::ASimpleFPSProjectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &ASimpleFPSProjectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
}

void ASimpleFPSProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor != nullptr && OtherActor != this && OtherComp != nullptr 
		&& (OtherActor->IsA(AStationaryEnemy::StaticClass()) || OtherActor->IsA(AMovingEnemy::StaticClass())))
	{
		if (OtherActor->IsA(AStationaryEnemy::StaticClass())) {
			AStationaryEnemy* enemy = Cast<AStationaryEnemy>(OtherActor);
			enemy->health -= FMath::RandRange(5, 10);
		}
		else {
			AMovingEnemy* enemy = Cast<AMovingEnemy>(OtherActor);
			enemy->health -= FMath::RandRange(5, 10);
		}
		Destroy();
	}
}