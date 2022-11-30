@echo off

echo start build...
SET option=%1

if not exist Pong2D (
    echo generate visual studio solution...
    Engine\Bin\premake5.exe vs2019
)

msbuild.exe Pong2D\Pong2D.sln -property:Configuration=%option% -target:Rebuild