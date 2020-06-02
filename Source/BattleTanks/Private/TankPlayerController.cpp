// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks/Public/Tank.h"
#include "TankPlayerController.h"

ATankPlayerController::ATankPlayerController()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (GetControlledTank() == nullptr)
    {
        return;
    }
    UE_LOG(LogTemp, Warning, TEXT("You are possessing %s"), *GetControlledTank()->GetName());
}

void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    AimAtCrosshair();
}


#pragma region My Methods
ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}


void ATankPlayerController::AimAtCrosshair()
{
    if (!GetControlledTank())
    {
        return;
    }

    // Get World location through crosshair IE Line trace
    // if hit hits land scape
    // aim the tank at that point
    // Line trace by single channel from the center of the camera out forward into the world by the distance of the weapon range
}

#pragma endregion 
