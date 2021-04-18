// Fill out your copyright notice in the Description page of Project Settings.


#include "DelegateWidget.h"
#include "Components/TextBlock.h"
#include "TestGameMode.h"
#include "Engine.h"

void UDelegateWidget::NativeConstruct()
{
	Super::NativeConstruct();

}

bool UDelegateWidget::Initialize()
{
	bool Success = Super::Initialize();

	if (!Success) return false;

	if (ScoreTextField)
	{
		UE_LOG(LogTemp, Warning, TEXT("ScoreTextField found"));

		UWorld* World = GetWorld();
		if (World != nullptr)
		{
			ATestGameMode* TestGameMode = Cast<ATestGameMode>(World->GetAuthGameMode());

			if (TestGameMode)
			{
				UE_LOG(LogTemp, Warning, TEXT("ScoreTextField found"));
				ScoreTextField->SetText(FText::FromString("game mode set"));
				ScoreTextField->TextDelegate.BindUFunction(this, "SetScoreField");
			}
		}
	}

	return true;
}

FText UDelegateWidget::SetScoreField()
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
