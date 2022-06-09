// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatformGameInstance.h"
#include "Engine/Engine.h"

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

void UPuzzlePlatformGameInstance::Host()
{
	UEngine* Engine = GetEngine();
	
	if (!ensure(Engine != nullptr))
	{
		return;
	}

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Hosting"));
}

void UPuzzlePlatformGameInstance::Join(const FString& Address)
{
	UEngine* Engine = GetEngine();

	if (!ensure(Engine != nullptr))
	{
		return;
	}

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));
}