// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks/Public/Tank.h"
#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
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
