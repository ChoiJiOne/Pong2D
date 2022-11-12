@echo off

echo generate project files...

if not exist Dump (
    echo don't exist dump directory...
    mkdir Dump
)

if exist Pong2D (
    echo already exist Pong2D...
)

echo run premake5.exe...
Engine\Bin\premake5.exe vs2019
start Pong2D\Pong2D.sln
PAUSE
