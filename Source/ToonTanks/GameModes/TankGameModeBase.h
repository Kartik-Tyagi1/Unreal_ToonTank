// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TankGameModeBase.generated.h"

class APawnTurret;
class APawnTank;
class APlayerControllerBase;


UCLASS()
class TOONTANKS_API ATankGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	void ActorDied(AActor* DeadActor);

protected:
	// Set GameMode information
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent) // Handle function implementation in derived blueprint class
	void GameStart();

	UFUNCTION(BlueprintImplementableEvent) // Handle function implementation in derived blueprint class
	void GameOver(bool PlayerWon);

	// EditDefaultsOnly -> Can be changed in defaults window in the blueprint window
	// BlueprintReadOnly -> Cannot use a blueprint node to set the value of the variable
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Loop")
	int32 StartDelay = 3;

private:
	// Handle C++ side of the game flow
	// Will be calling the blueprint GameStart and GameOver functions
	void HandleGameStart();
	void HandleGameOver(bool PlayerWon);

	int32 GetTargetTurretCount();

private:
	APawnTank* PlayerTank;
	int32 TargetTurrets = 0;
	APlayerControllerBase* PlayerControllerRef;

};
