workspace "Voyage"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Voyage/vendor/GLFW/include"
IncludeDir["Glad"] = "Voyage/vendor/Glad/include"
IncludeDir["ImGui"] = "Voyage/vendor/imgui"

include "Voyage/vendor/GLFW"
include "Voyage/vendor/Glad"
include "Voyage/vendor/imgui"

project "Voyage"
	location "Voyage"
	kind "SharedLib"
	language "c++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "vgpch.h"
	pchsource "Voyage/src/vgpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"VG_PLATFORM_WINDOWS",
			"VG_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "VG_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "VG_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "VG_DIST"
		buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "c++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Voyage/vendor/spdlog/include",
		"Voyage/src"
	}

	links
	{
		"Voyage"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0"

		defines
		{
			"VG_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "VG_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "VG_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "VG_DIST"
		buildoptions "/MD"
		optimize "On"