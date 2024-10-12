#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "NavigationKeyConfigBPLibrary.generated.h"

UCLASS()
class NAVIGATIONKEYCONFIG_API UNavigationKeyConfigBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "NavigationKeyConfig")
	static void AddNavigationKeyConfig(APlayerController* PlayerController, FKey Key, EUINavigation Navigation);

	UFUNCTION(BlueprintCallable, Category = "NavigationKeyConfig")
	static void AddNavigationKeyActionConfig(APlayerController* PlayerController, FKey Key,
	                                  EUINavigationAction NavigationAction);

	UFUNCTION(BlueprintCallable, Category = "NavigationKeyConfig")
	static void RemoveNavigationKeyConfig(APlayerController* PlayerController, FKey Key);

	UFUNCTION(BlueprintCallable, Category = "NavigationKeyConfig")
	static void RemoveNavigationKeyActionConfig(APlayerController* PlayerController, FKey Key);

	UFUNCTION(BlueprintCallable, Category = "NavigationKeyConfig")
	static void ClearNavigationKeyConfig(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category = "NavigationKeyConfig")
	static void ClearNavigationKeyActionConfig(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category = "NavigationKeyConfig")
	static void ResetToDefault(APlayerController* PlayerController);
};
