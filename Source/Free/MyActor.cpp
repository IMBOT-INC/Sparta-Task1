// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
}

void AMyActor::Move()
{
	FVector Target = FVector(
			FMath::FRandRange(-50.f, 50.f),
			FMath::FRandRange(-50.f, 50.f),
			0.f
			);
	AddActorWorldOffset(Target);
	FVector CurrentLocation = GetActorLocation();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1,
		                                 5,
		                                 FColor::Red,
		                                 CurrentLocation.ToString());
	}
	UE_LOG(LogTemp,
	       Warning, TEXT("Location %s" ),
	       *CurrentLocation.ToString())
}

void AMyActor::Turn()
{
	FRotator DeltaRotation = FRotator(
			0.f,
			FMath::FRandRange(-180.f, 180.f),
			0.f
			);
	
	AddActorWorldRotation(DeltaRotation);

	FRotator CurrentRotation = GetActorRotation();

	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(
			-1,
			5,
			FColor::Red,
			CurrentRotation.ToString());
	}
	UE_LOG(LogTemp, Warning, TEXT("Location %s" ), *CurrentRotation.ToString())
}


