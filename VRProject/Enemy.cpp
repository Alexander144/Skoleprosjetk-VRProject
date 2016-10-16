// Fill out your copyright notice in the Description page of Project Settings.

#include "VRProject.h"
#include "Enemy.h"


// Sets default values
AEnemy::AEnemy(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{


	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetActorEnableCollision(true);
	//CSphere = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("Root"));
	//CSphere->OnComponentHit.AddDynamic(this, &AEnemy::OnHit);
	//CSphere->SetSimulatePhysics(false);
	//CSphere->SetEnableGravity(false);
	//RootComponent = CSphere;

	DoShoot = true;
	//rotBall.ZeroRotator;
}

// Called when the game starts or when spawned
/*void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	locBall = FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z);
	FVector Direction = GetActorLocation() - BlueBaseLoc;
	Direction.Normalize();
	
	SetActorRotation(Direction.Rotation());
	
}*/

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if ((ShootingInterval*DeltaTime) <= 0 && DoShoot == true) {
	
		//Setter hvem som eier objektet som spawner
		FActorSpawnParameters spawn;
		spawn.Owner = this;
		spawn.Instigator = Instigator;
		ABallShoot* NewSpawnObject = GetWorld()->SpawnActor<ABallShoot>(Ball, locBall, rotBall, spawn);
		NewSpawnObject->SetSpeed(ShootingSpeed);


		ShootingInterval = 1000;
	}
	if (DoShoot == true) {
		ShootingInterval = ShootingInterval - 1;
	}
}
void AEnemy::OnHit(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	Health = Health - 10;
}

