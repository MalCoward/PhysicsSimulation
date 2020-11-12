// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelOneEuler.generated.h"

UCLASS()
class PHYSICSSIMULATION_API ALevelOneEuler : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelOneEuler();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Position)
		FVector currentPosition;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Position)
		FVector newPosition;

	FVector currentVelocity;
	FVector newVelocity;

	FVector gravityAcc;

	float startFrame;
	float currentFrame;

	void UpdatePosition();

};
