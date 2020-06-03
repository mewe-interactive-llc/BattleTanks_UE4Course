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

void ATankAIController::Tick(float DeltaTime)
{
    if (!GetPlayerTank())
    {
        return;
    }

    // TODO Move towards player

    // Get Player Location and aim at it
    FString AITankName = GetName();
    
    GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

    //TODO Attack player when ready 
    
    UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s "), *AITankName, *GetPlayerTank()->GetName());
}
