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

	// Plane Stuff
	hasCollidedWithPlane = false;
	ticksAfterPlane = 0;

	planeNormal = { 0.0f, 0.0f, 1.0f }; //Normal for horizontal plane
	
}

// Called every frame
void AStaticSphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (hasCollidedWithPlane)
	{
		if (ticksAfterPlane > 3)
		{
			hasCollidedWithPlane = false;
		}
		ticksAfterPlane++;
	}

	currentFrame++;
	UpdatePosition();

	if (PossiblePlaneCollision())
	{
		CheckForPlaneCollision();
	}

}

void AStaticSphere::UpdatePosition()
{

	newVelocity = currentVelocity + gravityAcc;
	newPosition = currentPosition + newVelocity;

	currentVelocity = newVelocity;
	currentPosition = newPosition;

	this->SetActorLocation(currentPosition);

}

bool AStaticSphere::PossiblePlaneCollision()
{
	planeNormalAngle = FVector::DotProduct(planeNormal, -currentVelocity);
	if (planeSphereAngle < 90 && (currentPosition.X < planeXMax && currentPosition.X > planeXMin && currentPosition.Y < planeYMax && currentPosition.Y > planeYMin))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void AStaticSphere::CheckForPlaneCollision()
{
	//// Using K as 0 0 0, with plane being at height 0
	//planeSphereAngle = FVector::DotProduct(planeNormal, currentPosition);
	//sphereHeight = FMath::Sin(planeSphereAngle) * currentPosition.Size();
	//if (sphereHeight <= radius)
	//{
	//	PlaneCollision();
	//}
	if ((currentPosition.Z <= radius) && !hasCollidedWithPlane)
	{
		PlaneCollision();
	}
}

void AStaticSphere::PlaneCollision()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Collided");
	currentVelocity.Z = -planeNormal.Z * currentVelocity.Z;
	ticksAfterPlane = 0;
	hasCollidedWithPlane = true;
}

void AStaticSphere::SetPlaneCollision()
{
	hasCollidedWithPlane = false;
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
