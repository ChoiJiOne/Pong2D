#include "ToyEngine.h"

void ToyEngine::Init()
{
	CommandLineUtils::Init();
	DebugUtils::Init();
	ContentUtils::Init();

	int32_t SDLFlags = SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER | SDL_INIT_EVENTS;
	int32_t SoundFlags = MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG | MIX_INIT_MID | MIX_INIT_OPUS;

	CHECK((SDL_Init(SDLFlags) == 0), "failed to initialize SDL");
	CHECK((Mix_Init(SoundFlags) & SoundFlags), "failed to initialize SDL_mixer");
	CHECK((Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == 0), "failed to open audio");
	CHECK((SDLNet_Init() == 0), "failed to initialize SDL_net");

#if defined(SHIPPING)
	ShowWindow(GetConsoleWindow(), SW_HIDE);
#endif
}

void ToyEngine::Quit()
{
	ContentUtils::Quit();

	SDLNet_Quit();
	Mix_Quit();
	SDL_Quit();
}
