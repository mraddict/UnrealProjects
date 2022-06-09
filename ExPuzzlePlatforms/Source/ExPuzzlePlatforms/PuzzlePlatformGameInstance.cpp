// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatformGameInstance.h"

UPuzzlePlatformGameInstance::UPuzzlePlatformGameInstance(const FObjectInitializer& ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("UPuzzlePlatformGameInstance::UPuzzlePlatformGameInstance"));
}

void UPuzzlePlatformGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("UPuzzlePlatformGameInstance::Init"));
}

void UPuzzlePlatformGameInstance::Shutdown()
{
	UE_LOG(LogTemp, Warning, TEXT("UPuzzlePlatformGameInstance::Shutdown"));
}
