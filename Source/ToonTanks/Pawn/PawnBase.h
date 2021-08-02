// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

class UCapsuleComponent;

UCLASS()
class TOONTANKS_API APawnBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnBase();

protected:
	// These next two functions will be called in the child classes
	// They will not be overidden
	void RotateTurretFunction(FVector LookAtTarget);
	void Fire();

	// The virtual keyword tells the compiler that this function will be overidden
	// Helpful for any error messages and more
	virtual void HandleDestruction();


private:
	// The UPROPERTY exposes these variables to the unreal editor
	// We cannot modify the variable itself in the editor but we can modify its details

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* CapsuleComp; // Collision component for pawn classes
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh; // For the base of the tank and turrets
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh; // For the firing parts of the tank and turrets
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint; // Visually represent spawn point of projectile
};
