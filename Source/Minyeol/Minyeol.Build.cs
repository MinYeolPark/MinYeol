// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Minyeol : ModuleRules
{
	public Minyeol(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "UMG"});

		PublicIncludePaths.Add("Minyeol/");

		PublicDependencyModuleNames.AddRange(new string[] { "GameplayAbilities", "GameplayTags", "GameplayTasks" });
    }
}
