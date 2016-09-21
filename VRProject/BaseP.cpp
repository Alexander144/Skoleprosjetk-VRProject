// Fill out your copyright notice in the Description page of Project Settings.

#include "VRProject.h"
#include "BaseP.h"


// Sets default values
ABaseP::ABaseP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseP::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

