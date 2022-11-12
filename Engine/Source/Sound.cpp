#include "Sound.h"

// @third party code - BEGIN
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
// @third party code - END

Sound::Sound(const std::string& InPath)
{
	Sound_ = Mix_LoadWAV(InPath.c_str());
	CHECK((Sound_ != nullptr), "failed to load sound file");
}

Sound::~Sound()
{
	if (Sound_)
	{
		Mix_FreeChunk(Sound_);
		Sound_ = nullptr;
	}
}

void Sound::Play()
{
	CHECK((Mix_PlayChannel(-1, Sound_, 0) != -1), "failed to play sound");
}