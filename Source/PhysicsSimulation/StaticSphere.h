// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StaticSphere.generated.h"

UCLASS()
class PHYSICSSIMULATION_API AStaticSphere : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStaticSphere();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Radius)
		float radius;
	float mass;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Movement)
		FVector currentVelocity;
	FVector newVelocity;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Movement)
		FVector gravityAcc;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Position)
		FVector currentPosition;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Position)
		FVector newPosition;

	float startFrame;
	float currentFrame;

	void UpdatePosition();

	// Plane Stuff
	bool PossiblePlaneCollision();

	FVector planeNormal;
	float planeSphereAngle;
	float planeNormalAngle;

	float sphereHeight;
	bool hasCollidedWithPlane;

	void CheckForPlaneCollision();
	void PlaneCollision();

	void SetPlaneCollision();
	int ticksAfterPlane;

	float planeXMin = -2500.0f;
	float planeXMax = 2500.0f;
	float planeYMin = -2500.0f;
	float planeYMax = 2500.0f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetVelocity(FVector velocity);
	void SetGravity(FVector gravity);

	float GetRadius();
	float GetMass();

};
