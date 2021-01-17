// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/Vector.h"
#include "LevelOneNewton.generated.h"

UCLASS()
class PHYSICSSIMULATION_API ALevelOneNewton : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelOneNewton();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Position)
		FVector position;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Position)
		FVector originalPosition;

	float radius;

	float xVelocity;
	float zVelocity;
	float zAcceleration;

	float startFrame;
	float currentFrame;

	float t;

	void UpdatePosition();

};
