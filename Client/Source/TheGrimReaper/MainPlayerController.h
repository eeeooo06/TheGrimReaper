// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

#include "MainCharacter.h"

#include "MainPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class THEGRIMREAPER_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
public:
	virtual void SetupInputComponent() override;

private:
	// Input Action 변수

	// 이동
	UPROPERTY(EditAnywhere, Category = "InputAction")
	TObjectPtr<UInputAction> IA_Move;

	// 시야
	UPROPERTY(EditAnywhere, Category = "InputAction")
	TObjectPtr<UInputAction> IA_Look;

	// 점프
	UPROPERTY(EditAnywhere, Category = "InputAction")
	TObjectPtr<UInputAction> IA_Jump;

	// Input Action 모음
	UPROPERTY(EditAnywhere, Category = "InputMappingContext")
	TObjectPtr<UInputMappingContext> IMC_Default;

public:
	// Input Action 함수

	UFUNCTION()
	void Move(const FInputActionValue& Value);

	UFUNCTION()
	void Look(const FInputActionValue& Value);

	UFUNCTION()
	void Jump(const FInputActionValue& Value);
};
