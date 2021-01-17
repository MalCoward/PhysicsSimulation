// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelOneEuler.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// Sets default values
ALevelOneEuler::ALevelOneEuler()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	currentVelocity = { 1000.0f / 60, 0.0f / 60, 500.0f / 60 };
	gravityAcc = { 0.0f / 60, 0.0f / 60, -9.8f / 60 };
}

// Called when the game starts or when spawned
void ALevelOneEuler::BeginPlay()
{
	Super::BeginPlay();

	currentPosition = this->GetActorLocation();
	startFrame = 0;
	currentFrame = startFrame;
	newPosition = currentPosition;
	newVelocity = currentVelocity;
	
}

// Called every frame
void ALevelOneEuler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (this->GetActorLocation().Z <= 0)
	{
		return;
	}
	else
	{
		currentFrame++;
		UpdatePosition();
	}
}

void ALevelOneEuler::UpdatePosition()
{

	newVelocity = currentVelocity + gravityAcc;
	newPosition = currentPosition + newVelocity;

	currentVelocity = newVelocity;
	currentPosition = newPosition;

	this->SetActorLocation(currentPosition);

}
