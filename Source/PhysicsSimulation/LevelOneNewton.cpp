// Fill out your copyright notice in the Description page of Project Settings.

#include "LevelOneNewton.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// Sets default values
ALevelOneNewton::ALevelOneNewton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	xVelocity = 1000.0f;
	zVelocity = 500.0f;
	zAcceleration = -9.8 * 60;

}

// Called when the game starts or when spawned
void ALevelOneNewton::BeginPlay()
{
	Super::BeginPlay();

	originalPosition = this->GetActorLocation();
	startFrame = 0;
	currentFrame = startFrame;
	position = originalPosition;
	
}

// Called every frame
void ALevelOneNewton::Tick(float DeltaTime)
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

void ALevelOneNewton::UpdatePosition()
{

	t = currentFrame / 60;
	position.X = originalPosition.X + (xVelocity * t);
	position.Z = originalPosition.Z + (zVelocity * t) + ((zAcceleration * (t * t)) / 2);

	this->SetActorLocation(position);

}
