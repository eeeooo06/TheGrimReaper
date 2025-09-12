// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerController.h"

#include "InputMappingContext.h"
#include "InputAction.h"

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(IMC_Default, 0);
	}
}

void AMainPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* UEIC = Cast<UEnhancedInputComponent>(InputComponent))
	{
		UEIC->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AMainPlayerController::Move);
		UEIC->BindAction(IA_Look, ETriggerEvent::Triggered, this, &AMainPlayerController::Look);
		UEIC->BindAction(IA_Jump, ETriggerEvent::Started, this, &AMainPlayerController::Jump);
	}
}

void AMainPlayerController::Move(const FInputActionValue& Value)
{
	const FVector2D Input = Value.Get<FVector2D>();

	if (AMainCharacter* Char = Cast<AMainCharacter>(GetPawn()))
	{
		Char->HandleMoveInput(Input);
	}
}

void AMainPlayerController::Look(const FInputActionValue& Value)
{
	const FVector2D LookInput = Value.Get<FVector2D>();

	AddYawInput(LookInput.X * 0.5f);
	AddPitchInput(LookInput.Y * 0.5f);
}

void AMainPlayerController::Jump(const FInputActionValue& Value)
{
	const bool bIsJump = Value.Get<bool>();
	if (AMainCharacter* Char = Cast<AMainCharacter>(GetPawn()))
	{
		Char->HandleJumpInput(true);
	}
}