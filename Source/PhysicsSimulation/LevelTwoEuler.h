// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StaticSphere.h"
#include "GameFramework/Actor.h"
#include "LevelTwoEuler.generated.h"

UCLASS()
class PHYSICSSIMULATION_API ALevelTwoEuler : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelTwoEuler();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* sphereMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Position)
		FVector currentPosition;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Position)
		FVector newPosition;

	float radius;
	float mass;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Movement)
		FVector currentVelocity;
	FVector newVelocity;

	FVector gravityAcc;

	float startFrame;
	float currentFrame;

	void UpdatePosition();

	// Second Ball Stuff
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Collision)
		class AStaticSphere* staticSphere;

	FVector staticSpherePosition;
	float staticSphereRadius;
	float staticSphereMass;

	bool PossibleCollision();

	FVector vectorBetweenTwoSpheres;
	float distanceBetweenTwoSpheres;
	float angleBetweenVectors;
	float angleBetweenVectorsTwo;
	float shortestDistance;

	void Collision();
	FVector collisionPoint;
	FVector staticSphereMovementVector;
	FVector staticNewVelocity;

	bool hasCollided;
	float originalMomentum;
	float staticNewMomentum;
	float newMomentum;

	// Plane Stuff
	bool PossiblePlaneCollision();

	FVector planeNormal;
	float planeSphereAngle;
	float planeNormalAngle;

	float sphereHeight;
	bool hasCollidedWithPlane;
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

};
