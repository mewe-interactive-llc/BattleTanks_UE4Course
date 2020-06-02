// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()



public:

	ATankPlayerController();
	class ATank* GetControlledTank () const;

	void AimAtCrossHair();

	UPROPERTY(EditAnywhere, Category = "Crosshair Coordinates")
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere, Category = "Crosshair Coordinates")
	float CrossHairYLocation = 0.33333;
	
	


protected:
	virtual void BeginPlay () override;

	virtual void Tick(float DeltaTime) override;

private:
	bool GetRayHitLocation(FVector& OutHitLocation ) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	
	
	
};
