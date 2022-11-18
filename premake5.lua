workspace "Pong2D"

    configurations { 
        "Debug",
        "Release",
        "Shipping",
    }

    platforms {
        "Win64"
    }

    location "%{wks.name}"

    engine="%{wks.location}/../Engine"

    thirdparty="%{engine}/ThirdParty"

    game="%{wks.location}/../Game"

    project "Engine"
        kind "StaticLib"

        language "C++"

        cppdialect "C++17"

        includedirs {
            "%{engine}/Source",

            "%{thirdparty}/Include",
        }

        files {
            "%{engine}/Source/*",
            "%{engine}/Source/Component/*",
            "%{engine}/Source/Core/*",
            "%{engine}/Source/Misc/*",
            "%{engine}/Source/Resource/*",
            "%{engine}/Source/UI/*",
            
            "%{thirdparty}/Include/json/*",

            "%{thirdparty}/Include/SDL2/*",

            "%{thirdparty}/Include/spdlog/*",
            "%{thirdparty}/Include/spdlog/cfg/*",
            "%{thirdparty}/Include/spdlog/details/*",
            "%{thirdparty}/Include/spdlog/fmt/*",
            "%{thirdparty}/Include/spdlog/fmt/bundled/*",
            "%{thirdparty}/Include/spdlog/sinks/*",

            "%{thirdparty}/Include/stb/*",
        }

        filter "configurations:Debug"
            defines { "DEBUG" }
            runtime  "Debug"
            optimize "Off"
            symbols "On"
            debugdir "%{thirdparty}/Debug"

            links {
                "Dbghelp.lib",
                "%{thirdparty}/Debug/SDL2.lib",
                "%{thirdparty}/Debug/SDL2main.lib",
                "%{thirdparty}/Debug/SDL2_mixer.lib",
                "%{thirdparty}/Debug/SDL2_net.lib",
            }

        filter "configurations:Release"
            defines { "RELEASE" }
            runtime "Release"
            optimize "On"
            symbols "On"
            debugdir "%{thirdparty}/Release"
            
            links {
                "Dbghelp.lib",
                "%{thirdparty}/Release/SDL2.lib",
                "%{thirdparty}/Release/SDL2main.lib",
                "%{thirdparty}/Release/SDL2_mixer.lib",
                "%{thirdparty}/Release/SDL2_net.lib",
            }
        
        filter "configurations:Shipping"
            defines { "SHIPPING" }
            runtime "Release"
            optimize "Full"
            symbols "Off"
            debugdir "%{thirdparty}/Release"

            links {
                "Dbghelp.lib",
                "%{thirdparty}/Release/SDL2.lib",
                "%{thirdparty}/Release/SDL2main.lib",
                "%{thirdparty}/Release/SDL2_mixer.lib",
                "%{thirdparty}/Release/SDL2_net.lib",
            }

    project "Game"
        kind "ConsoleApp"

        language "C++"

        cppdialect "C++17"

        links {"Engine"}

        debugargs {
            "-Content=%{wks.location}..\\Game\\Content\\",
            "-Dump=%{wks.location}..\\Dump\\"
        }

        includedirs {
            "%{engine}/Source",
            "%{thirdparty}/Include",
            "%{game}/Source",
        }

        files {
            "%{game}/Source/*",
            "%{game}/Content/*",
        }

        filter "configurations:Debug"
            defines { "DEBUG" }
            runtime  "Debug"
            optimize "Off"
            symbols "On"
            debugdir "%{thirdparty}/Debug"

        filter "configurations:Release"
            defines { "RELEASE" }
            runtime "Release"
            optimize "On"
            symbols "On"
            debugdir "%{thirdparty}/Release"
        
        filter "configurations:Shipping"
            defines { "SHIPPING" }
            runtime "Release"
            optimize "Full"
            symbols "Off"
            debugdir "%{thirdparty}/Release"
