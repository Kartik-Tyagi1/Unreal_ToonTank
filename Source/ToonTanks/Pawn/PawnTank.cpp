// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


APawnTank::APawnTank()
{
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    SpringArm->SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void APawnTank::BeginPlay()
{
	Super::BeginPlay();

    // This is similar as before, store a reference so we don't have to find it all the time
    PlayerControllerRef = Cast<APlayerController>(GetController());
	
}

void APawnTank::HandleDestruction() 
{
    Super::HandleDestruction();
    Destroy();
    
}

// Called every frame
void APawnTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    Rotate();
    Move();

    if(PlayerControllerRef)
    {
        FHitResult TraceHitResult;
        PlayerControllerRef->GetHitResultUnderCursor( // Tracks mouse cursor for turret to face
            ECC_Visibility,
            false,
            TraceHitResult
        );
        FVector HitLocation = TraceHitResult.ImpactPoint;

        RotateTurret(HitLocation);
    }
}

// Called to bind functionality to input
void APawnTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &APawnTank::CalculateMoveInput);
    PlayerInputComponent->BindAxis("Turn", this, &APawnTank::CalculateRotateInput);

    PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APawnTank::Fire);

}


void APawnTank::CalculateMoveInput(float value) 
{
    MoveDirection = FVector(value * MoveSpeed * GetWorld()->DeltaTimeSeconds, 0, 0);
}

void APawnTank::CalculateRotateInput(float value) 
{
    float RotateAmount = value * RotateSpeed * GetWorld()->DeltaTimeSeconds;
    FRotator Rotation = FRotator(0, RotateAmount, 0);
    RotationDirection = FQuat(Rotation);
}

void APawnTank::Move() 
{
    AddActorLocalOffset(MoveDirection, true);
}

void APawnTank::Rotate() 
{
    AddActorLocalRotation(RotationDirection, true);
}
