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

    auto PlayerTank = GetPlayerTank();
    if (!PlayerTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("Player controller not found"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("We found this Player Tank and the bitch name is %s"), *PlayerTank->GetName());
    }

    if (GetControlledTank() == nullptr)
    {
        return;
    }
    else
    {
       
        UE_LOG(LogTemp, Warning, TEXT("This tank is auto possessed by an AI Controller "));
    }
    
}
