#pragma once

#include "CoreMinimal.h"
#include "OverrideNavigationConfig.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "NavigationKeyConfigSubsystem.generated.h"

UCLASS()
class UNavigationKeyConfigSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	FOverrideNavigationConfig& GetOverrideNavigationConfig() const;

private:
	TSharedPtr<FOverrideNavigationConfig> OverrideNavigationConfig;
};
