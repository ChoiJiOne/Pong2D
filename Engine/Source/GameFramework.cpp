#include "Core/GameFramework.h"
#include "Core/World.h"
#include "Core/Input.h"
#include "Core/Renderer.h"
#include "Core/Window.h"

#include "ToyEngine.h"

GameFramework::~GameFramework()
{
	if (World_) World_.reset();
	if (Input_) Input_.reset();
	if (Renderer_) Renderer_.reset();
	if (Window_) Window_.reset();

	ToyEngine::Quit();
}

void GameFramework::Init()
{
	ToyEngine::Init();
}