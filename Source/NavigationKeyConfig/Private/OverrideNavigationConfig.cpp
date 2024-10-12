#include "OverrideNavigationConfig.h"

FOverrideNavigationConfig::FOverrideNavigationConfig()
{
	DefaultKeyEventRules = KeyEventRules;
	DefaultKeyActionRules = KeyActionRules;	
}

void FOverrideNavigationConfig::SetKeyEventRule(const FKey& Key, const EUINavigation Navigation)
{
	KeyEventRules.Add(Key, Navigation);
}

void FOverrideNavigationConfig::SetKeyActionRule(const FKey& Key, const EUINavigationAction NavigationAction)
{
	KeyActionRules.Add(Key, NavigationAction);
}

void FOverrideNavigationConfig::RemoveKeyEventRule(const FKey& Key)
{
	KeyEventRules.Remove(Key);
}

void FOverrideNavigationConfig::RemoveKeyActionRule(const FKey& Key)
{
	KeyActionRules.Remove(Key);
}

void FOverrideNavigationConfig::ClearKeyEventRules()
{
	KeyEventRules.Empty();
}

void FOverrideNavigationConfig::ClearKeyActionRules()
{
	KeyActionRules.Empty();
}

void FOverrideNavigationConfig::ResetToDefault()
{
	KeyEventRules = DefaultKeyEventRules;
	KeyActionRules = DefaultKeyActionRules;
}
