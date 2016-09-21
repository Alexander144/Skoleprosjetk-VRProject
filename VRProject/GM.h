// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Enemy.h"
#include "GM.generated.h"

UCLASS()
class VRPROJECT_API AGM : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 ShootingSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 ShootingInterval;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<AEnemy> Ball; //Send in blueprint


																		  // Sets default values for this actor's properties
	AGM(const FObjectInitializer& ObjectInitializer);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

private:
	FVector locBall;
	FRotator rotBall;
};