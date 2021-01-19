// Fill out your copyright notice in the Description page of Project Settings.


#include "StaticSphere.h"

// Sets default values
AStaticSphere::AStaticSphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	currentVelocity = { 0.0f / 60, 0.0f / 60, 0.0f / 60 };
	gravityAcc = { 0.0f / 60, 0.0f / 60, 0.0f / 60 };

	radius = 25.0f;
	mass = 1.0f;

}

// Called when the game starts or when spawned
void AStaticSphere::BeginPlay()
{
	Super::BeginPlay();

	currentPosition = this->GetActorLocation();
	startFrame = 0;
	currentFrame = startFrame;
	newPosition = currentPosition;
	newVelocity = currentVelocity;
	
}

// Called every frame
void AStaticSphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	currentFrame++;
	UpdatePosition();

}

void AStaticSphere::UpdatePosition()
{

	newVelocity = currentVelocity + gravityAcc;
	newPosition = currentPosition + newVelocity;

	currentVelocity = newVelocity;
	currentPosition = newPosition;

	this->SetActorLocation(currentPosition);

}

void AStaticSphere::SetVelocity(FVector velocity)
{
	currentVelocity = velocity;
}

void AStaticSphere::SetGravity(FVector gravity)
{
	gravityAcc = gravity;
}

float AStaticSphere::GetRadius()
{
	return radius;
}

float AStaticSphere::GetMass()
{
	return mass;
}
