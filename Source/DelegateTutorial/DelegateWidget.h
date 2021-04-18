// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DelegateWidget.generated.h"

/**
 * 
 */
UCLASS()
class DELEGATETUTORIAL_API UDelegateWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

protected: 
	
	bool Initialize() override;
	

private:

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* ScoreTextField;

	UPROPERTY()
		class ATestGameMode* TGM;

	UFUNCTION()
		FText SetScoreField();
};
