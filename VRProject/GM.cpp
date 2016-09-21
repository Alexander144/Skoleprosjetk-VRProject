// Fill out your copyright notice in the Description page of Project Settings.

#include "VRProject.h"
#include "GM.h"


// Sets default values
AGM::AGM(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{


	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	rotBall.ZeroRotator;
	locBall = FVector(this->GetActorLocation().X + 500, this->GetActorLocation().Y + 200, this->GetActorLocation().Z + 700);
}

// Called when the game starts or when spawned
void AGM::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AGM::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if ((ShootingInterval*DeltaTime) <= 0) {

		//Setter hvem som eier objektet som spawner
		FActorSpawnParameters spawn;
		spawn.Owner = this;
		spawn.Instigator = Instigator;
		AEnemy* NewSpawnObject = GetWorld()->SpawnActor<AEnemy>(Ball, locBall, rotBall, spawn);

		ShootingInterval = 1000;
	}
	ShootingInterval = ShootingInterval - 1;
}