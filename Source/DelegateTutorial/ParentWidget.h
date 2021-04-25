// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ParentWidget.generated.h"

/**
 * 
 */
UCLASS()
class DELEGATETUTORIAL_API UParentWidget : public UUserWidget
{
	GENERATED_BODY()
	

public:

	virtual void NativeConstruct() override;

protected:

	bool Initialize() override;

private:

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* ScoreText;

	UFUNCTION()
		FText SetScoreField();


};
