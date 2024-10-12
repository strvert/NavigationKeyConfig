#pragma once

#include "CoreMinimal.h"
#include "Framework/Application/NavigationConfig.h"

class FOverrideNavigationConfig final : public FNavigationConfig
{
public:
	FOverrideNavigationConfig();

	void SetKeyEventRule(const FKey& Key, const EUINavigation Navigation);

	void SetKeyActionRule(const FKey& Key, const EUINavigationAction NavigationAction);

	void RemoveKeyEventRule(const FKey& Key);

	void RemoveKeyActionRule(const FKey& Key);

	void ClearKeyEventRules();

	void ClearKeyActionRules();

	void ResetToDefault();

private:
	TMap<FKey, EUINavigation> DefaultKeyEventRules;
	TMap<FKey, EUINavigationAction> DefaultKeyActionRules;
};
