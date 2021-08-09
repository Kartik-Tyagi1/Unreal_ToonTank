// Fill out your copyright notice in the Description page of Project Settings.

/*
 * The PlayerController is the interface that directly recieves 
 *	user input notifications when something is pressed and also
 *	what is used to enable or disable player input
*/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API APlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

public:
	void SetPlayerEnableState(bool SetPlayerEnable);
	
};
