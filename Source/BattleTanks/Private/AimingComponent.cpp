// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTanks/Public/AimingComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UAimingComponent::UAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	BarrelMesh = BarrelToSet;
}



void UAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!BarrelMesh)
	{
		return;
	}

	FVector OutLaunchVelocity;
	FVector StartLocation = BarrelMesh->GetSocketLocation(FName("LaunchSocket"));
	
	if (UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		ESuggestProjVelocityTraceOption::DoNotTrace
	))

	{
		FVector AimDirection = OutLaunchVelocity.GetSafeNormal();
		UE_LOG(LogTemp, Warning, TEXT(" Aiming at %s "), *AimDirection.ToString());
		MoveBarrelTowards(AimDirection);
	}

	
}

void UAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	FRotator BarrelRot = BarrelMesh->GetForwardVector().Rotation();
	FRotator AimRot = AimDirection.Rotation();
	FRotator DeltaRo = AimRot - BarrelRot;
	
	UE_LOG(LogTemp, Warning, TEXT("AimAsRotator: %s "), *AimRot.ToString());
	// take the barrels current rotation and forward vector to equal the hit locations
}

