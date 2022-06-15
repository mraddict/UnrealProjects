// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ExPuzzlePlatforms : ModuleRules
{
	public ExPuzzlePlatforms(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "UMG" });
	}
}
