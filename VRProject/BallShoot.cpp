// Fill out your copyright notice in the Description page of Project Settings.

#include "VRProject.h"
#include "BallShoot.h"


// Sets default values
ABallShoot::ABallShoot(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetActorEnableCollision(true);
	CSphere = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("Root"));

	CSphere->SetSimulatePhysics(true);
	CSphere->SetEnableGravity(false);
	//CSphere->OnComponentHit(this, &ABallShoot::OnHit);

	RootComponent = CSphere;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	MyMesh->AttachTo(RootComponent);
	m_speed = 1;
	Force = false;
}

// Called when the game starts or when spawned
void ABallShoot::BeginPlay()
{
	Super::BeginPlay();

	Player = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	Direction = Player - GetActorLocation();
}

// Called every frame
void ABallShoot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MyMesh->WakeRigidBody();
	MyMesh->AddForce((Direction / 2)*m_speed);
}
void ABallShoot::SetSpeed(int32 Speed) {
	m_speed = Speed;
}
void ABallShoot::OnHit(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	Destroy();
}
