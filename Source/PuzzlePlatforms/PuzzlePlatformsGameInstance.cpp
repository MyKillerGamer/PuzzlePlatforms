// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzlePlatformsGameInstance.h"

#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"

UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer &ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("From constructor!"));
}

void UPuzzlePlatformsGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("From Init()!"));
}

void UPuzzlePlatformsGameInstance::Host()
{
	UEngine* Engine = GetEngine();
	if(!ensure(Engine != nullptr)) { return; }

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Hosting"));

	UWorld* World = GetWorld();
	if(!ensure(World != nullptr)) { return; }

	World->ServerTravel("/Game/Dynamic/Levels/ThirdPersonExampleMap?listen");
}

void UPuzzlePlatformsGameInstance::Join(const FString& Address)
{
	UEngine* Engine = GetEngine();
	if(!ensure(Engine != nullptr)) { return; }

	Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, FString::Printf(TEXT("Joining: %s"), *Address));

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if(!ensure(PlayerController != nullptr)) { return; }

	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}