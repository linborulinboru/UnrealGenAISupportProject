// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class unreal_llm_api_test : ModuleRules
{
	public unreal_llm_api_test(ReadOnlyTargetRules Target) : base(Target)
	{
		PrivateDependencyModuleNames.AddRange(new string[] { "GenerativeAISupport" });
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
