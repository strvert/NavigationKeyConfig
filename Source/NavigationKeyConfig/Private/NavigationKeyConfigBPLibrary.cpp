#include "NavigationKeyConfigBPLibrary.h"
#include "NavigationKeyConfigSubsystem.h"

inline UNavigationKeyConfigSubsystem* GetNavigationKeyConfigSubsystem(const APlayerController* PlayerController)
{
	if (PlayerController)
	{
		const ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer();
		check(LocalPlayer);

		return LocalPlayer->GetSubsystem<UNavigationKeyConfigSubsystem>();
	}
	return nullptr;
}

template <typename Func>
bool ExecuteNavigationKeyConfig(APlayerController* PlayerController, Func&& Function)
{
	if (const UNavigationKeyConfigSubsystem* Subsystem = GetNavigationKeyConfigSubsystem(PlayerController))
	{
		FOverrideNavigationConfig& OverrideNavigationConfig = Subsystem->GetOverrideNavigationConfig();
		Function(OverrideNavigationConfig);
		return true;
	}
	return false;
}

void UNavigationKeyConfigBPLibrary::AddNavigationKeyConfig(APlayerController* PlayerController, const FKey Key,
                                                           EUINavigation Navigation)
{
	ExecuteNavigationKeyConfig(PlayerController,
	                           [Key, Navigation](FOverrideNavigationConfig& OverrideNavigationConfig)
	                           {
		                           OverrideNavigationConfig.SetKeyEventRule(Key, Navigation);
	                           });
}

void UNavigationKeyConfigBPLibrary::AddNavigationKeyActionConfig(APlayerController* PlayerController, const FKey Key,
                                                                 const EUINavigationAction NavigationAction)
{
	ExecuteNavigationKeyConfig(PlayerController,
	                           [Key, NavigationAction](FOverrideNavigationConfig& OverrideNavigationConfig)
	                           {
		                           OverrideNavigationConfig.SetKeyActionRule(Key, NavigationAction);
	                           });
}

void UNavigationKeyConfigBPLibrary::RemoveNavigationKeyConfig(APlayerController* PlayerController, FKey Key)
{
	ExecuteNavigationKeyConfig(PlayerController,
	                           [Key](FOverrideNavigationConfig& OverrideNavigationConfig)
	                           {
		                           OverrideNavigationConfig.RemoveKeyEventRule(Key);
	                           });
}

void UNavigationKeyConfigBPLibrary::RemoveNavigationKeyActionConfig(APlayerController* PlayerController, FKey Key)
{
	ExecuteNavigationKeyConfig(PlayerController,
	                           [Key](FOverrideNavigationConfig& OverrideNavigationConfig)
	                           {
		                           OverrideNavigationConfig.RemoveKeyActionRule(Key);
	                           });
}

void UNavigationKeyConfigBPLibrary::ClearNavigationKeyConfig(APlayerController* PlayerController)
{
	ExecuteNavigationKeyConfig(PlayerController,
	                           [](FOverrideNavigationConfig& OverrideNavigationConfig)
	                           {
		                           OverrideNavigationConfig.ClearKeyEventRules();
	                           });
}

void UNavigationKeyConfigBPLibrary::ClearNavigationKeyActionConfig(APlayerController* PlayerController)
{
	ExecuteNavigationKeyConfig(PlayerController,
	                           [](FOverrideNavigationConfig& OverrideNavigationConfig)
	                           {
		                           OverrideNavigationConfig.ClearKeyActionRules();
	                           });
}

void UNavigationKeyConfigBPLibrary::ResetToDefault(APlayerController* PlayerController)
{
	ExecuteNavigationKeyConfig(PlayerController,
	                           [](FOverrideNavigationConfig& OverrideNavigationConfig)
	                           {
		                           OverrideNavigationConfig.ResetToDefault();
	                           });
}
