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
        //UE_LOG(LogTemp, Warning, TEXT("Hit Direction: %s"), * HitLocation.ToString());
    }
    // Get World location through crosshair IE Line trace
    // if hit hits land scape
    // aim the tank at that point
    // Line trace by single channel from the center of the camera out forward into the world by the distance of the weapon range
}

bool ATankPlayerController::GetRayHitLocation(FVector& OutHitLocation) const
{
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);
    
    // Find CrossHair Position.
    FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
    FVector LookDirection; // output parameter placeholder for &WorldDirection
    
    // Here we create our own variable to tell the function below to output the information it has out through them so we can read them at runtime.
    if ( GetLookDirection(ScreenLocation, LookDirection ))
    {
        UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), * LookDirection.ToString());
    }
   
    //line trace through that direciton
    return true;
    
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
   
    FVector CameraLocation; // output parameter placeholder for &CameraWorldLocation
   
    if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraLocation, LookDirection))
    {
        return true;
    }

    return false;
}


#pragma endregion 
