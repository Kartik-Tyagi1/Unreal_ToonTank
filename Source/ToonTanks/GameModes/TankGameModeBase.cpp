// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameModeBase.h"


void ATankGameModeBase::BeginPlay() 
{
    // Get references and game win/lose conditions
    // Call HandleGameStart() to initialize the start countdown, turret activation, pawn check etc. 
}

void ATankGameModeBase::ActorDied(AActor* DeadActor) 
{
    // Check what type of actor has died
    // If turret died increase kill count
    // If player died go to lose condition
}

void ATankGameModeBase::HandleGameStart() 
{
    // Initialize the start countdown, turret activation, pawn check etc. 
    // Call blueprint version of GameStart()
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon) 
{
    // See if player has destroyed all the turrets and show win
    // If the player is destoryed show the loss
    // Call blueprint version of GameOver()
}
