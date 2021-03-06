workspace "Sophia"
	architecture "x64"

	configurations 
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["glfw"] = "Sophia/vendor/glfw/include"
IncludeDir["glad"] = "Sophia/vendor/glad/include"
IncludeDir["imgui"] = "Sophia/vendor/imgui"

include "Sophia/vendor/glfw"
include "Sophia/vendor/glad"
include "Sophia/vendor/imgui"

project "Sophia"
	location "Sophia"
	kind "Sharedlib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "sppch.h"
	pchsource "Sophia/src/sppch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.glfw}",
		"%{IncludeDir.glad}",
		"%{IncludeDir.imgui}"
	}

	links 
	{
		"GLFW",
		"GLAD",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"SP_PLATFORM_WINDOWS",
			"SP_BUILD_DLL",
			"SP_ENABLE_ASSERTS",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "SP_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "SP_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "SP_DIST"
		buildoptions "/MD"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Sophia/vendor/spdlog/include",
		"Sophia/src"
	}

	links
	{
		"Sophia"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"SP_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SP_DEBUG"
		buildoptions "/MDd"
		symbols "On"
		

	filter "configurations:Release"
		defines "SP_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "SP_DIST"
		buildoptions "/MD"
		optimize "On"
	
	