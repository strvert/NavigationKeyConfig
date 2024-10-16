#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NavigationKeyConfigBPLibrary.generated.h"

UCLASS()
class NAVIGATIONKEYCONFIG_API UNavigationKeyConfigBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * 指定したキーに対して、指定した UI ナビゲーションを設定します。
	 */
	UFUNCTION(BlueprintCallable, Category = "NavigationKeyConfig")
	static void AddNavigationKey(APlayerController* PlayerController, FKey Key, EUINavigation Navigation);

	/**
	 * 指定したキーに対して、指定した UI アクションを設定します。
	 */
	UFUNCTION(BlueprintCallable, Category = "NavigationKeyConfig")
	static void AddNavigationKeyAction(APlayerController* PlayerController, FKey Key,
	                                  EUINavigationAction NavigationAction);
	/**
	 * 指定したキーに設定された UI ナビゲーションを削除します。
	 */
	UFUNCTION(BlueprintCallable, Category = "NavigationKeyConfig")
	static void RemoveNavigationKey(APlayerController* PlayerController, FKey Key);

	/**
	 * 指定したキーに設定された UI アクションを削除します。
	 */
	UFUNCTION(BlueprintCallable, Category = "NavigationKeyConfig")
	static void RemoveNavigationKeyAction(APlayerController* PlayerController, FKey Key);

	/**
	 * UI ナビゲーションの設定をクリアし、すべてのキーから設定を削除します。
	 */
	UFUNCTION(BlueprintCallable, Category = "NavigationKeyConfig")
	static void ClearAllNavigationKey(APlayerController* PlayerController);

	/**
	 * UI アクションの設定をクリアし、すべてのキーから設定を削除します。
	 */
	UFUNCTION(BlueprintCallable, Category = "NavigationKeyConfig")
	static void ClearAllNavigationKeyAction(APlayerController* PlayerController);

	/**
	 * UI ナビゲーションの設定をエンジンのデフォルトにリセットします。
	 */
	UFUNCTION(BlueprintCallable, Category = "NavigationKeyConfig")
	static void ResetToDefault(APlayerController* PlayerController);
};
