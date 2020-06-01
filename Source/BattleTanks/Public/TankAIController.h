// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()


public:
	class ATank* GetControlledTank () const;

	class ATank* GetPlayerTank () const;


protected:
    virtual void BeginPlay () override;
	
};
