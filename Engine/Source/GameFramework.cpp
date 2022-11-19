#include <GameFramework.h>
#include <World.h>
#include <Input.h>
#include <Renderer.h>
#include <Window.h>

#include <ToyEngine.h>

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