// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameModeBase.h"
#include "ToonTanks/Pawn/PawnTank.h"
#include "ToonTanks/Pawn/PawnTurret.h"
#include "Kismet/GameplayStatics.h"


void ATankGameModeBase::BeginPlay() 
{
    Super::BeginPlay();

    // Get references and game win/lose conditions
    // Call HandleGameStart() to initialize the start countdown, turret activation, pawn check etc. 
    HandleGameStart();
}

void ATankGameModeBase::ActorDied(AActor* DeadActor) 
{
    // Check what type of actor has died
    
    // If player died go to lose condition
    if(DeadActor == PlayerTank)
    {
        PlayerTank->HandleDestruction();
        HandleGameOver(false);
    }
    // If turret died increase kill count
    else if(APawnTurret* DestroyedTurret = Cast<APawnTurret>(DeadActor))
    {
        DestroyedTurret->HandleDestruction();
        if(--TargetTurrets == 0)
        {
            HandleGameOver(true);
        }
    }

}

void ATankGameModeBase::HandleGameStart() 
{
    // Initialize the start countdown, turret activation, pawn check etc. 
    // Call blueprint version of GameStart()
    
    TargetTurrets = GetTargetTurretCount();
    PlayerTank = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));

    GameStart();
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon) 
{
    // See if player has destroyed all the turrets and show win
    // If the player is destoryed show the loss
    // Call blueprint version of GameOver()
    GameOver(PlayerWon);
}

int32 ATankGameModeBase::GetTargetTurretCount() 
{
    TArray<AActor*> TurretActors;
    // StaticClass returns UClass of actor type, not an object instance
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), APawnTurret::StaticClass(), TurretActors);
    return TurretActors.Num();
}
