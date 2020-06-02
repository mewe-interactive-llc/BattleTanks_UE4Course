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

	void AimAtCrosshair();


protected:
	virtual void BeginPlay () override;

	virtual void Tick(float DeltaTime) override;
	
};
