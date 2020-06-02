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
    
}

void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    AimAtCrossHair();
}




#pragma region My Methods
ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}


void ATankPlayerController::AimAtCrossHair()
{
    if (!GetControlledTank())
    {
        return;
    }
    
    FVector HitLocation;
    if (GetRayHitLocation(HitLocation))
    {
        UE_LOG(LogTemp, Warning, TEXT("Hit Direction: %s"), * HitLocation.ToString());
    }
    // Get World location through crosshair IE Line trace
    // if hit hits land scape
    // aim the tank at that point
    // Line trace by single channel from the center of the camera out forward into the world by the distance of the weapon range
}

bool ATankPlayerController::GetRayHitLocation(FVector& OutHitLocation) const
{
    // Here we create our own variable to tell the function below to output the information it has out through them so we can read them at runtime.
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);

    // Find CrossHair Position.
    FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
    
    
    
   
    //line trace through that direciton
   

    
    return true;
    
}



#pragma endregion 
