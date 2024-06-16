workspace "BusinessSuits"
	configurations { "Debug", "Release" }

project "business_suits"
	kind "WindowedApp"
	language "C++"
	cppdialect "C++20"
	targetdir "."

	files { "src/**.hpp", "src/**.cpp" }
	links { "SDL2", "GL", "GLEW" }
	includedirs { "src" }

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"
