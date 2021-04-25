// Fill out your copyright notice in the Description page of Project Settings.


#include "ParentWidget.h"
#include "TestGameMode.h"
#include "Components/TextBlock.h"

void UParentWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

bool UParentWidget::Initialize()
{
	bool Success = Super::Initialize();

	if (!Success) return false;

	if (ScoreText)
	{
		UE_LOG(LogTemp, Warning, TEXT("Score text found"));

		UWorld* World = GetWorld();

		if (World != nullptr)
		{
			ATestGameMode* TestGameMode = Cast<ATestGameMode>(World->GetAuthGameMode());

			if (TestGameMode) 
			{
				UE_LOG(LogTemp, Warning, TEXT("Game mode found"));

				ScoreText->SetText(FText::FromString("Game mode set"));

				ScoreText->TextDelegate.BindUFunction(this, "SetScoreField");


			}
		}
	}

	return true;
}

FText UParentWidget::SetScoreField()
{
	UWorld* World = GetWorld();

	if (World != nullptr)
	{
		ATestGameMode* TestGameMode = Cast<ATestGameMode>(World->GetAuthGameMode());

		if (TestGameMode)
		{
			return FText::FromString(FString::FromInt(TestGameMode->GetScorePoints()));
		}

		else
		{
			return FText::FromString("NULL");
		}
	}

	return FText::FromString("NULL");
}
