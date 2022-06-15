// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatformGameInstance.h"

#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "MenuSystem/MainMenu.h"
#include "MenuSystem/InGameMenu.h"

UPuzzlePlatformGameInstance::UPuzzlePlatformGameInstance(const FObjectInitializer& ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("UPuzzlePlatformGameInstance::UPuzzlePlatformGameInstance"));
	/**/
	// set main menu class to our Blueprinted class
	ConstructorHelpers::FClassFinder<UUserWidget> MainMenuBPClass(TEXT("/Game/MenuSystem/WBP_MainMenu"));
	if (MainMenuBPClass.Class != NULL)
	{
		MainMenuClass = MainMenuBPClass.Class;
	}	

	ConstructorHelpers::FClassFinder<UUserWidget> InGameMenuBPClass(TEXT("/Game/MenuSystem/WBP_InGameMenu"));
	if (InGameMenuBPClass.Class != NULL)
	{
		InGameMenuClass = InGameMenuBPClass.Class;
	}
}

void UPuzzlePlatformGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("UPuzzlePlatformGameInstance::Init"));
}

void UPuzzlePlatformGameInstance::Shutdown()
{
	UE_LOG(LogTemp, Warning, TEXT("UPuzzlePlatformGameInstance::Shutdown"));
}

void UPuzzlePlatformGameInstance::LoadMainMenu()
{
	if (!ensure(MainMenuClass != nullptr))
	{
		return;
	}

	MainMenu = CreateWidget<UMainMenu>(this, MainMenuClass);

	if (!ensure(MainMenu != nullptr))
	{
		return;
	}

	MainMenu->SetUp();
	MainMenu->SetMenuInterface(this);
}

void UPuzzlePlatformGameInstance::Host()
{
	if (MainMenu != nullptr)
	{
		MainMenu->TearDown();
	}

	UEngine* Engine = GetEngine();
	
	if (!ensure(Engine != nullptr))
	{
		return;
	}

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Hosting"));

	UWorld* World = GetWorld();

	if (!ensure(World != nullptr))
	{
		return;
	}

	World->ServerTravel("/Game/Maps/Game01?listen");
}

void UPuzzlePlatformGameInstance::Join(const FString& Address)
{
	if (MainMenu != nullptr)
	{
		MainMenu->TearDown();
	}

	UEngine* Engine = GetEngine();

	if (!ensure(Engine != nullptr))
	{
		return;
	}

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));

	APlayerController* PlayerController = GetFirstLocalPlayerController();

	if (!ensure(PlayerController != nullptr))
	{
		return;
	}

	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}

void UPuzzlePlatformGameInstance::ExitInGame()
{
	APlayerController* PlayerController = GetFirstLocalPlayerController();

	if (!ensure(PlayerController != nullptr))
	{
		return;
	}

	PlayerController->ClientTravel("/Game/Maps/MainMenu", ETravelType::TRAVEL_Absolute);
}

void UPuzzlePlatformGameInstance::LoadInGameMenu()
{
	if (!ensure(InGameMenuClass != nullptr))
	{
		return;
	}

	InGameMenu = CreateWidget<UInGameMenu>(this, InGameMenuClass);

	if (!ensure(InGameMenu != nullptr))
	{
		return;
	}

	//InGameMenu->SetUp();
	//InGameMenu->SetMenuInterface(this);
}