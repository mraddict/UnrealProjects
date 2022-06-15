// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"

void UMenuWidget::SetUp()
{
	this->AddToViewport();

	UWorld* World = GetWorld();

	if (!ensure(World != nullptr))
	{
		return;
	}

	APlayerController* PlayerController = World->GetFirstPlayerController();

	if (!ensure(PlayerController != nullptr))
	{
		return;
	}

	FInputModeUIOnly InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetWidgetToFocus(this->TakeWidget());
	//this->bIsFocusable = true;

	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = true;
}

void UMenuWidget::TearDown()
{
	this->RemoveFromViewport();

	UWorld* World = GetWorld();

	if (!ensure(World != nullptr))
	{
		return;
	}

	APlayerController* PlayerController = World->GetFirstPlayerController();

	if (!ensure(PlayerController != nullptr))
	{
		return;
	}

	FInputModeGameOnly InputModeData;

	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = false;
}

void UMenuWidget::SetMenuInterface(IMenuInterface* MI)
{
	this->MenuInterface = MI;
}
