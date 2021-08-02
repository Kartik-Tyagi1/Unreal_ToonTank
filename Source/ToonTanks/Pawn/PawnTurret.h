// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTurret.generated.h"

/*
 * This is a simple AI that tracks the player tank 
 * 		- Checks if player tank is in certain range
 * 		- Turret will then fire every n seconds
 */
UCLASS()
class TOONTANKS_API APawnTurret : public APawnBase
{
	GENERATED_BODY()
	

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when game starts or when spawned
	virtual void BeginPlay() override;	

private:
	void CheckFireCondition();

private:
	FTimerHandle FireRateTimerHandle; // Bind and unbind a timer for the fire rate
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float FireRate = 2.f;
};
