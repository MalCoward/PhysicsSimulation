// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* sphereMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Position)
		FVector currentPosition;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Position)
		FVector newPosition;

	float radius;

	FVector currentVelocity;
	FVector newVelocity;

	FVector gravityAcc;

	float startFrame;
	float currentFrame;

	void UpdatePosition();

};
