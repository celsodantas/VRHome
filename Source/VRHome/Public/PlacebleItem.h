// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VRGameBaseActor.h"
#include "PlacebleItem.generated.h"

UCLASS()
class VRHOME_API APlacebleItem : public AVRGameBaseActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APlacebleItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	FString GetDisplayName() { return DisplayName; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DisplayName = TEXT("Default Name");
};
