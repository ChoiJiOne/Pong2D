#include "Music.h"

// @third party code - BEGIN
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
// @third party code - END

Music::Music(const std::string& InPath)
{
	Music_ = Mix_LoadMUS(InPath.c_str());
	CHECK((Music_ != nullptr), "failed to load music file");
}

Music::~Music()
{
	if (Music_)
	{
		Mix_FreeMusic(Music_);
		Music_ = nullptr;
	}
}

void Music::Play(bool bIsLoop)
{
	CHECK((Mix_PlayMusic(Music_, static_cast<int32_t>(bIsLoop)) == 0), "failed to play music");
}

bool Music::IsPlay() const
{
	return (Mix_PlayingMusic() != 0);
}

void Music::Stop()
{
	Mix_PauseMusic();
}

bool Music::IsStop() const
{
	return (Mix_PausedMusic() != 0);
}

void Music::Resume()
{
	Mix_ResumeMusic();
}
