// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h" // Timer functionality

void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

    // Implementing timer
	GetWorld()->GetTimerManager().SetTimer(
        FireRateTimerHandle, 
        this, 
        &APawnTurret::CheckFireCondition,
        FireRate,
        true);
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
   
}

void APawnTurret::CheckFireCondition() 
{
    // If player is valid and isnt dead then fire
    // If player is in range then fire

    UE_LOG(LogTemp, Warning, TEXT("Fire Condition Checked"));

}