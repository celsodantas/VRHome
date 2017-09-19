// Fill out your copyright notice in the Description page of Project Settings.

#include "AssetsFolderReaderLibrary.h"
#include "Engine/ObjectLibrary.h"
#include "VRGameBaseActor.h"

UAssetsFolderReaderLibrary::UAssetsFolderReaderLibrary(class FObjectInitializer const & pcip) : Super(pcip)
{
}

void UAssetsFolderReaderLibrary::GetAllFurnituresClasses(FString pathToFolder, UClass* classFilter, TArray<UClass*>& result)
{
	auto ObjectLibrary = UObjectLibrary::CreateLibrary(classFilter, true, true);

	if (ObjectLibrary != nullptr)
	{
		//ObjectLibrary->AddToRoot();
		ObjectLibrary->LoadBlueprintsFromPath(pathToFolder);

		//TArray<FAssetData> actorClasses;
		//ObjectLibrary->GetAssetDataList(actorClasses);
		TArray<UBlueprintGeneratedClass*> blueprintClasses;
		ObjectLibrary->GetObjects<UBlueprintGeneratedClass>(blueprintClasses);
		UE_LOG(LogTemp, Warning, TEXT("[UAssetsFolderReaderLibrary] Found assets: %d"), blueprintClasses.Num());

		for (int index = 0; index < blueprintClasses.Num(); ++index)
		{
			result.Add(blueprintClasses[index]);

			UE_LOG(LogTemp, Warning, TEXT(" - %s"), *blueprintClasses[index]->GetName());
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ObjectLibrary not loaded"));
	}
}

