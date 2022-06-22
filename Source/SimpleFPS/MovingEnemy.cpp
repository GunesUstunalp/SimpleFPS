// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingEnemy.h"

// Sets default values
AMovingEnemy::AMovingEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	if (CubeVisualAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

	health = 100;
}

// Called when the game starts or when spawned
void AMovingEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovingEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * 20.0f;       //Scale our height by a factor of 20
	float DeltaRotation = DeltaTime * 20.0f;    //Rotate by 20 degrees per second
	NewRotation.Yaw += DeltaRotation;
	SetActorLocationAndRotation(NewLocation, NewRotation);

	if (health <= 0)
		Destroy();

	ASimpleFPSCharacter* myCharacter = Cast<ASimpleFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (myCharacter != nullptr) {
		distanceToCharacter = (GetActorLocation() - myCharacter->GetActorLocation()).Size();
		if (distanceToCharacter < triggerRadius && distanceToCharacter > 100) {
			NewLocation = GetActorLocation() - (GetActorLocation() - myCharacter->GetActorLocation()) * 0.01f;
			SetActorLocationAndRotation(NewLocation, NewRotation);
		}
	}
}

