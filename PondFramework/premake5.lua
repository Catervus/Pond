workspace "Pond"

	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDirs = {}
IncludeDirs["SDL2"] = "%{prj.name}/vendor/SDL2/include"

-- SDL2 premake file	
-- include "Pond/vendor/SDL2/premake5.lua" 

project "Pond"

	location "Pond"

	kind "SharedLib" --dll

	language "C"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.c"
	}

	includedirs -- no includes yet
	{
		--"%{prj.name}/vendor/SDL2/include",
		"dependencies/SDL2/include",
		"dependencies/SDL2_image/include",
		"dependencies/SDL2_mixer/include",
		"dependencies/SDL2_ttf/include"
	}

	libdirs
	{
		--"%{prj.name}/vendor/SDL2/Binaries/Debug-windows-x86_64",
		"dependencies/SDL2_image/lib/x64",
		"dependencies/SDL2_mixer/lib/x64",
		"dependencies/SDL2/lib/x64",
		"dependencies/SDL2_ttf/lib/x64"

	}

	links
	{
		--"SDL2",
		"SDL2.lib",
		"SDL2_image.lib",
		"SDL2_mixer.lib",
		"SDL2_ttf.lib"
	}


	filter "system:windows"
		-- C dialect cdialect "C bla"

		staticruntime "On" --linking runtime libraries statically

		systemversion "latest" -- windows sdk verion

		defines
		{
			"POND_PLATFORM_WINDOWS",
			"POND_BUILD_DLL"
		}

		postbuildcommands
		{
			-- copies Pond dll into Sandbox exe folder
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"),
		}

		filter "configurations:Debug"
			defines "POND_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "POND_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "POND_DIST"
			optimize "On"


project "Sandbox"

	location "Sandbox"

	kind "ConsoleApp"

	language "C"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.c"
	}

	includedirs -- no includes yet
	{
		-- "%{prj.name}/vendor/xx/include"
		"Pond/src",
		--"Pond/vendor/SDL2/include",
		"dependencies/SDL2/include",
		"dependencies/SDL2_image/include",
		"dependencies/SDL2_mixer/include",
		"dependencies/SDL2_ttf/include"
	}

	postbuildcommands
	{
			--("{COPY} stuff") --  .. outputdir .. "/Sandbox"
			--("{COPY} Stuff/Stuff.txt ../Stuff2")

			("{COPY} assets $(OutDir)/assets"),

			("{COPY} ../dependencies/SDL2/lib/x64/SDL2.dll $(OutDir)"),

			("{COPY} ../dependencies/SDL2_image/lib/x64/SDL2_image.dll $(OutDir)"),
			("{COPY} ../dependencies/SDL2_image/lib/x64/libjpeg-9.dll $(OutDir)"),
			("{COPY} ../dependencies/SDL2_image/lib/x64/libpng16-16.dll $(OutDir)"),
			("{COPY} ../dependencies/SDL2_image/lib/x64/libwebp-7.dll $(OutDir)"),
			("{COPY} ../dependencies/SDL2_image/lib/x64/zlib1.dll $(OutDir)"),
			--("{COPY} ../bin/Debug-windows-x86_64/Pond/Pond.dll %{cfg.buildtarget.relpath}")
			("{COPY} ../dependencies/SDL2_mixer/lib/x64/SDL2_mixer.dll $(OutDir)"),

			("{COPY} ../dependencies/SDL2_ttf/lib/x64/SDL2_ttf.dll $(OutDir)"),

	}

	

	libdirs
	{
		--"Pond/vendor/SDL2/Binaries/Debug-windows-x86_64",
		"dependencies/Pond/lib",
		"dependencies/SDL2/lib/x64",
		"dependencies/SDL2_image/lib/x64",
		"dependencies/SDL2_mixer/lib/x64",
		"dependencies/SDL2_ttf/lib/x64"
	}

	links
	{
		"Pond",
		-- "SDL2",
		"SDL2.lib",
		"SDL2_image.lib",
		"SDL2_mixer.lib",
		"SDL2_ttf.lib"
	}

	filter "system:windows"
		-- C dialect cdialect "C bla"

		staticruntime "On" --linking runtime libraries statically

		systemversion "latest" -- windows sdk verion

		defines
		{
			"POND_PLATFORM_WINDOWS"
		}
		

		filter "configurations:Debug"
			defines "POND_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "POND_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "POND_DIST"
			optimize "On"


			
---------------------------------------------------------------------
--[[
project "Metroidvania_Month"

	location "Metroidvania_Month"

	kind "ConsoleApp"

	language "C"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.c"
	}

	includedirs -- no includes yet
	{
		-- "%{prj.name}/vendor/xx/include"
		"Pond/src",
		--"Pond/vendor/SDL2/include",
		"dependencies/SDL2/include",
		"dependencies/SDL2_image/include",
		"dependencies/SDL2_mixer/include"
	}

	postbuildcommands
	{
			--("{COPY} stuff") --  .. outputdir .. "/Sandbox"
			--("{COPY} Stuff/Stuff.txt ../Stuff2")

			("{COPY} assets/ $(OutDir)/assets"),

			("{COPY} ../dependencies/SDL2/lib/x64/SDL2.dll $(OutDir)"),

			("{COPY} ../dependencies/SDL2_image/lib/x64/SDL2_image.dll $(OutDir)"),
			("{COPY} ../dependencies/SDL2_image/lib/x64/libjpeg-9.dll $(OutDir)"),
			("{COPY} ../dependencies/SDL2_image/lib/x64/libpng16-16.dll $(OutDir)"),
			("{COPY} ../dependencies/SDL2_image/lib/x64/libwebp-7.dll $(OutDir)"),
			("{COPY} ../dependencies/SDL2_image/lib/x64/zlib1.dll $(OutDir)"),
			--("{COPY} ../bin/Debug-windows-x86_64/Pond/Pond.dll %{cfg.buildtarget.relpath}")
			("{COPY} ../dependencies/SDL2_mixer/lib/x64/SDL2_mixer.dll $(OutDir)"),

	}

	

	libdirs
	{
		--"Pond/vendor/SDL2/Binaries/Debug-windows-x86_64",
		"dependencies/SDL2/lib/x64",
		"dependencies/SDL2_image/lib/x64",
		"dependencies/SDL2_mixer/lib/x64"
	}

	links
	{
		"Pond",
		-- "SDL2",
		"SDL2.lib",
		"SDL2_image.lib",
		"SDL2_mixer.lib"
	}

	filter "system:windows"
		-- C dialect cdialect "C bla"

		staticruntime "On" --linking runtime libraries statically

		systemversion "latest" -- windows sdk verion

		defines
		{
			"POND_PLATFORM_WINDOWS"
		}
		

		filter "configurations:Debug"
			defines "POND_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "POND_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "POND_DIST"
			optimize "On"
]]
