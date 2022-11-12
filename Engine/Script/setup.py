import sys
import os
import shutil

# 게임 프로젝트가 초기화 되었는지 확인합니다.
# 이때, 게임 프로젝트는 단 한 번만 초기화 되어야 합니다.
def is_setup_project():
    project_dir = "Game/"
    return os.path.isdir(project_dir)


# 파일을 삭제합니다.
def remove_file(file_path):
    if os.path.exists(file_path):
        os.remove(file_path)


# 디렉토리를 삭제합니다.
def remove_directory(directory_path):
    if os.path.exists(directory_path):
        shutil.rmtree(directory_path)


# 게임 프로젝트 상태를 초기 상태로 설정합니다.
def cleanup_project():
    remove_file("GenerateProjectFiles.bat")
    remove_file("premake5.lua")
    remove_file(".gitignore")
    remove_directory("Game")


# 게임 프로젝트를 초기화합니다.
def setup_project():
    project_name = sys.argv[1]

    create_generate_project_files_script(project_name)
    create_premake5_script(project_name)
    create_git_ignore_file(project_name)
    create_game_directory()
    create_directory("Dump")


# 파일을 생성합니다.
def create_file(file_path, script_source):
    with open(file_path, "wt") as script_file:
        script_file.write(script_source)


# 디렉토리를 생성합니다.
def create_directory(directory_path):
    if not os.path.exists(directory_path):
        os.makedirs(directory_path)


# git ignore 파일을 생성합니다.
def create_git_ignore_file(project_name):
    script_source="{}".format(project_name + "\nDump")
    create_file(".gitignore", script_source)


# 게임 프로젝트의 premake5.lua 스크립트를 생성합니다.
def create_premake5_script(project_name):
    script_source="""workspace "{}"
""".format(project_name)

    script_source +="""
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
            "-Content=%{wks.location}..\\\\Game\\\\Content\\\\",
            "-Dump=%{wks.location}..\\\\Dump\\\\"
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
"""

    create_file("premake5.lua", script_source)


# 게임 프로젝트의 GenerateProjectFiles.bat 스크립트를 생성합니다.
def create_generate_project_files_script(project_name):
    script_source = """@echo off

echo generate project files...

if not exist Dump (
    echo don't exist dump directory...
    mkdir Dump
)

if exist {} (
    echo already exist {}...
)

echo run premake5.exe...
Engine\\Bin\\premake5.exe vs2019
start {}\\{}.sln
PAUSE
""".format(project_name, project_name, project_name, project_name)

    create_file("GenerateProjectFiles.bat", script_source)


# 게임 디렉토리를 생성합니다.
def create_game_directory():
    game_dir = "Game"
    content_dir = "Game/Content"
    source_dir = "Game/Source"

    create_directory(game_dir)
    create_directory(content_dir)
    create_directory(source_dir)

    create_file(source_dir + "/Main.cpp", "")
    create_file(content_dir + "/Content.json", "")


# 이 모듈이 메인 모듈일 경우, 하위 루틴을 실행합니다.
if __name__ == '__main__':
    if len(sys.argv) >= 2:
        if is_setup_project():
            print("warning! this project already setup...")
            cleanup_project()
        setup_project()
        print("done!")
    else:
        print("please insert project name in command line argument...")