// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "ToonTanks/GameModes/TankGameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// Variable initialisation should not be in the constructor
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = DefaultHealth; 

	// Gets context of current world and current active gamemode
	GameModeRef = Cast<ATankGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	
	// Create Dynamic Binding between the owning actor and our TakeDamage() function
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage);
}

void UHealthComponent::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, 
					AController* InstigatedBy, AActor* DamageCauser) 
{
	if(Damage == 0 || Health <= 0)
		return;

	Health = FMath::Clamp(Health - Damage, 0.0f, DefaultHealth);

	if(Health <= 0)
	{
		if(GameModeRef)
		{
			GameModeRef->ActorDied(GetOwner());
		}
		else 
		{
			UE_LOG(LogTemp, Warning, TEXT("Health Component has no reference to the GameMode"));
		}
	}
}



