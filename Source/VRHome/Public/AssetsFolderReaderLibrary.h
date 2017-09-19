// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/BlueprintGeneratedClass.h"
#include "AssetsFolderReaderLibrary.generated.h"

/**
 *
 */
UCLASS()
class VRHOME_API UAssetsFolderReaderLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static void GetAllFurnituresClasses(FString pathToFolder, UClass* classFilter, TArray<UClass*>& result);
};
