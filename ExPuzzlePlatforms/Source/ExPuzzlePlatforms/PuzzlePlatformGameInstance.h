// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuSystem/MenuInterface.h"
#include "PuzzlePlatformGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class EXPUZZLEPLATFORMS_API UPuzzlePlatformGameInstance : public UGameInstance , public IMenuInterface
{
	GENERATED_BODY()
	
public:

	// Constructor
	UPuzzlePlatformGameInstance(const FObjectInitializer& ObjectInitializer);

	/** virtual function to allow custom GameInstances an opportunity to set up what it needs */
	virtual void Init() override;
	/** virtual function to allow custom GameInstances an opportunity to do cleanup when shutting down */
	virtual void Shutdown() override;

	//
	UFUNCTION(BlueprintCallable)
	void LoadMainMenu();

	UFUNCTION(Exec)
	virtual void Host() override;
	UFUNCTION(Exec)
	virtual void Join(const FString& Address) override;
	// 인게임 종료
	virtual void ExitInGame() override;
	//
	UFUNCTION(BlueprintCallable)
	void LoadInGameMenu();

private:

	TSubclassOf<class UUserWidget> MainMenuClass;
	class UMainMenu* MainMenu;

	TSubclassOf<class UUserWidget> InGameMenuClass;
	class UInGameMenu* InGameMenu;
};
