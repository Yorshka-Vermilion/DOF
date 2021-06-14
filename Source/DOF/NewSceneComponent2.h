// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "CineCameraComponent.h"
#include "ImageUtils.h"
#include "Camera/CameraComponent.h"
#include "NewSceneComponent2.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DOF_API UNewSceneComponent2 : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNewSceneComponent2();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY()
		UCineCameraComponent* test2;

	UFUNCTION()
		void TraceLine();
	UPROPERTY()
		AActor* LastViewed;
	UPROPERTY()
		FVector staraLokacja;
};
