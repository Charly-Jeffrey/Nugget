workspace "Nugget"
    architecture "x64"

    configurations 
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder ( solution )
IncludeDir = {}
IncludeDir["GLFW"] = "Nugget/vendor/GLFW/include"

-- Include GLFW premake file
include "Nugget/vendor/GLFW"

project "Nugget"
    location "Nugget"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "NGpch.h"
    pchsource "Nugget/src/NGpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    links 
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "NG_PLATFORM_WINDOWS",
            "NG_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "NG_DEBUG"
        symbols "On"

        defines
        {
            "NG_ENABLE_ASSERTS"
        }
    
        
    filter "configurations:Release"
        defines "NG_RELEASE"
        optimize "On"

    
    filter "configurations:Dist"
        defines "NG_DIST"
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
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "Nugget/vendor/spdlog/include",
        "Nugget/src"
    }

    links
    {
        "Nugget"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "NG_PLATFORM_WINDOWS"
        }
    
    filter "configurations:Debug"
        defines "NG_DEBUG"
        symbols "On"
    
        
    filter "configurations:Release"
        defines "NG_RELEASE"
        optimize "On"

    
    filter "configurations:Dist"
        defines "NG_DIST"
        optimize "On"

        