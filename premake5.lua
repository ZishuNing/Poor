workspace "PoorEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

-- Output directory for the solution
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "PoorEngine"
	location "PoorEngine"
	kind "SharedLib"
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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PR_PLATFORM_WINDOWS",
			"PR_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} \"%{cfg.buildtarget.relpath}\" \"../bin/" .. outputdir .. "/Sandbox\"")
		}


	filter "configurations:Debug"
		defines "PR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PR_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PR_DIST"
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
		"PoorEngine/vendor/spdlog/include",
		"PoorEngine/src"
	}

	links
	{
		"PoorEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PR_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "PR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PR_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PR_DIST"
		optimize "On"
