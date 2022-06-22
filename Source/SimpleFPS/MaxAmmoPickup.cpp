// Fill out your copyright notice in the Description page of Project Settings.


#include "MaxAmmoPickup.h"

// Sets default values
AMaxAmmoPickup::AMaxAmmoPickup()
{
	PrimaryActorTick.bCanEverTick = false;

	AmmoPickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AmmoPickupMesh"));
	RootComponent = AmmoPickupMesh;

	PickupBox = CreateDefaultSubobject<UBoxComponent>(TEXT("PickupBox"));
	PickupBox->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	PickupBox->SetGenerateOverlapEvents(true);
	PickupBox->OnComponentBeginOverlap.AddDynamic(this, &AMaxAmmoPickup::OnPickupEvent);
	PickupBox->AttachToComponent(AmmoPickupMesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
}

// Called when the game starts or when spawned
void AMaxAmmoPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMaxAmmoPickup::OnPickupEvent(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult)
{
	ASimpleFPSCharacter* myProjectCharacter = Cast<ASimpleFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	myProjectCharacter->AddMaxAmmo(ammoPickupVal);

	Destroy();
}

