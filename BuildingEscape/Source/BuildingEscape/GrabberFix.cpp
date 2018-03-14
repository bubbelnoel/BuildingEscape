// Fill out your copyright notice in the Description page of Project Settings.

#include "GrabberFix.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

#define OUT

// Sets default values for this component's properties
UGrabberFix::UGrabberFix()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabberFix::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabberFix::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewPointLocation, OUT PlayerViewPointRotation);

	/*auto PlayerViewLocationString = PlayerViewPointLocation.ToString();
	auto PlayerViewRotationString = PlayerViewPointRotation.ToString();

	UE_LOG(LogTemp, Warning, TEXT("Location %s Position %s"), *PlayerViewLocationString, *PlayerViewRotationString);*/

	FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;

	DrawDebugLine(GetWorld(), PlayerViewPointLocation, LineTraceEnd, FColor(255, 0, 0), false, 0.f, 50.f, 10.f);
}

