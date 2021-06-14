// Fill out your copyright notice in the Description page of Project Settings.


#include "NewSceneComponent2.h"
#include "Components/PostProcessComponent.h"

// Sets default values for this component's properties
UNewSceneComponent2::UNewSceneComponent2()
{

	PrimaryComponentTick.bCanEverTick = true;

}

void UNewSceneComponent2::TraceLine()
{
	FVector Loc;
	FRotator Rot;
	FHitResult Hit;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(Loc, Rot);

	FVector Start = Loc;
	FVector End = Start + (Rot.Vector() * 20000);

	FCollisionQueryParams TraceParams;
	GetWorld()->LineTraceSingleByChannel(Hit,Start,End,ECC_Visibility,TraceParams);
	
	if(Hit.Distance < 20000)
	{
		test2->FocusSettings.ManualFocusDistance = Hit.Distance;
	}else
	{
		test2->FocusSettings.ManualFocusDistance = 20000;

	}
}


// Called when the game starts
void UNewSceneComponent2::BeginPlay()
{
	Super::BeginPlay();
	
	USceneComponent* test = this->GetChildComponent(0);
	test2 = Cast<UCineCameraComponent>(test);
	if(test2)
	{
		UE_LOG(LogTemp,Warning,TEXT("DZIALA"));

		test2->PostProcessSettings.bOverride_DepthOfFieldFocalDistance = 1;
		test2->PostProcessSettings.DepthOfFieldFocalDistance = 50;
		test2->PostProcessSettings.DepthOfFieldMethod_DEPRECATED = EDepthOfFieldMethod::DOFM_CircleDOF;
	}else
	{
		UE_LOG(LogTemp,Warning,TEXT("Nie dziala"));
	}
	// ...
	
}


// Called every frame
void UNewSceneComponent2::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if(test2)
	{
		TraceLine();
	}
	// ...
}

