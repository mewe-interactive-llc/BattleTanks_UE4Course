// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "BattleTanks/Public/Tank.h"

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
        // Line trace by single channel from the center of the camera out forward into the world by the distance of the weapon range
        
        UE_LOG(LogTemp, Warning, TEXT("Hit Direction: %s"), * HitLocation.ToString());

        GetControlledTank()->AimAt(HitLocation);
    }
    // Get World location through crosshair IE Line trace
    // if hit hits land scape
    // aim the tank at that point
   
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
        GetLookVectorHitLocation(LookDirection, OutHitLocation);
    }
   
    //line trace through that direction
    return true;
    
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
    FVector CameraLocation; // output parameter placeholder for &CameraWorldLocation
    return (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraLocation, LookDirection));
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const
{
    FHitResult HitResult;
    FVector StartLocation = PlayerCameraManager->GetCameraLocation();
    FVector EndLocation = StartLocation + (LookDirection * LineTraceRange);
    if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility))
    {
        OutHitLocation = HitResult.Location;
        return true;
    }

    OutHitLocation = FVector(0);
    return false;
}


#pragma endregion 
