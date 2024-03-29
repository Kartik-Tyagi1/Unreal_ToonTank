// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h" // Timer functionality
#include "PawnTank.h"

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

    /* 
    * Instead of doing a constant check every two seconds shown in CheckFireCondition
    * We can create a APawnTank reference in the beginning of the game
    * That way it saves some resources when doing the check
    */
    PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void APawnTurret::HandleDestruction() 
{
    // Called the PawnBase function first
    Super::HandleDestruction();

    Destroy();
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    if(!PlayerPawn || ReturnDistanceToPlayer() > FireRange)
        return;

    // The base function already includes the actors location
    RotateTurret(PlayerPawn->GetActorLocation());
   
}

void APawnTurret::CheckFireCondition() 
{
    // If player is valid and isnt dead then fire
    // SORT OF OKAY WAY ---> if(UGameplayStatics::GetPlayerPawn(this, 0))
   
   if(!PlayerPawn || !PlayerPawn->GetIsPlayerAlive())
       return;


    // If player is in range and alive then fire
    if(ReturnDistanceToPlayer() <= FireRange)
        Fire();
}

float APawnTurret::ReturnDistanceToPlayer() 
{
    if(!PlayerPawn)
       return 0.0;

    return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation()); 
}