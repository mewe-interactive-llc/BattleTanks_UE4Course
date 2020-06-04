// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAimingComponent();

	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

protected:


	

public:	


	void AimAt(FVector HitLocation, float LaunchSpeed);

	

private:
	class UStaticMeshComponent* BarrelMesh = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
};
