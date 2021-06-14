// Fill out your copyright notice in the Description page of Project Settings.


#include "NewSceneComponent.h"

// Sets default values for this component's properties
UNewSceneComponent::UNewSceneComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UNewSceneComponent::BeginPlay()
{
	Super::BeginPlay();
	USceneComponent* test = this->GetChildComponent(0);
	if(test)
	{
		UE_LOG(LogTemp,Warning,TEXT("OK"));
	}else
	{
		UE_LOG(LogTemp,Warning,TEXT("Nie dziala"));
	}
	// ...
	
}


// Called every frame
void UNewSceneComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	UE_LOG(LogTemp,Warning,TEXT("GIT(NSC)"));
	// ...
}

