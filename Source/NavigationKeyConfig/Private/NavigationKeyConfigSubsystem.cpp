#include "NavigationKeyConfigSubsystem.h"

void UNavigationKeyConfigSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	OverrideNavigationConfig = MakeShared<FOverrideNavigationConfig>();

	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (const TSharedPtr<FSlateUser> SlateUser = LocalPlayer->GetSlateUser())
		{
			SlateUser->SetUserNavigationConfig(OverrideNavigationConfig);
		}
	}
}

FOverrideNavigationConfig& UNavigationKeyConfigSubsystem::GetOverrideNavigationConfig() const
{
	return *OverrideNavigationConfig;
}
