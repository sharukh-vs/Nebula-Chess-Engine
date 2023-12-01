workspace "NebulaChessEngine"

    startproject "Sandbox"

    configurations {
        "Debug",
        "Release"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    platforms "Win64"

    filter { "platforms:Win64 "}
        system "Windows"
        architecture "x86_64"
        defines "NCE64"

    project "NebulaChessEngine"
        kind "StaticLib"
        language "C++"
        staticruntime "off"

        targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
        objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

        files {
            "%{prj.name}/Src/**.h",
            "%{prj.name}/Src/**.cpp",
            "%{prj.name}/Dependencies/**.h",
            "%{prj.name}/Dependencies/**.cpp",
        }

        includedirs {
            "%{wks.location}/%{prj.name}/Src"
        }

        location "%{wks.location}/%{prj.name}"

        filter { "configurations:Debug"}
            defines "NDEBUG"
            runtime "Debug"
            symbols "On"

        filter { "configurations:Release" }
            defines "NRELEASE"
            runtime "Release"
            optimize "On"

    project "Sandbox"
        kind "ConsoleApp"
        language "C++"

        targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
        objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

        files {
            "%{prj.name}/**.h",
            "%{prj.name}/**.cpp",
        }

        includedirs {
            "%{wks.location}/NebulaChessEngine/Src",
        }

        location "%{wks.location}/%{prj.name}"

        links {
            "NebulaChessEngine",
        }

        filter { "configurations:Debug"}
            defines { "NDEBUG" }
            runtime "Debug"
            symbols "On"

        filter { "configurations:Release" }
            defines "NRELEASE"
            runtime "Release"
            optimize "On"
