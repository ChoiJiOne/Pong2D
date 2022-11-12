#include "GameFramework.h"
#include "ToyEngine.h"

GameFramework::~GameFramework()
{
	if (World_) World_.reset();
	if (Input_) Input_.reset();
	if (Graphics_) Graphics_.reset();
	if (Window_) Window_.reset();

	ToyEngine::Quit();
}

void GameFramework::Init()
{
	ToyEngine::Init();
}