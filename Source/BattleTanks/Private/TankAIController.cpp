// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "BattleTanks/Public/Tank.h"

ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
    auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
    if (!PlayerTank)
    {
        return nullptr;
    }
    return Cast<ATank>(PlayerTank);
}

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();

    
    
}
