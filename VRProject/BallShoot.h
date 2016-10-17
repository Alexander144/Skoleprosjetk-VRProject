// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Basep.h"
#include "BallShoot.generated.h"

UCLASS()
class VRPROJECT_API ABallShoot : public AActor
{
	GENERATED_BODY()

public:
	//UPROPERTY(EditAnywhere, BlueprintReadWrite) UShapeComponent *CSphere;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite) UStaticMeshComponent *MyMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector Target;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector Base;
	//FVector Direction;
	int32 m_speed;
	// Sets default values for this actor's properties
	ABallShoot(const FObjectInitializer& ObjectInitializer);

	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;

	// Called every frame
	//virtual void Tick(float DeltaSeconds) override;

	UFUNCTION()
		void OnHit(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	void ABallShoot::SetSpeed(int32 Speed);
	bool Force;

private:
};