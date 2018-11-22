#pragma once
#include <vector>
#include <SDL2/SDL.h>
namespace toryengine
{
	class Keyboard
	{
	public:
		bool GetKey(SDL_Keycode keyCode);
		bool GetKeyDown(SDL_Keycode keyCode);
		bool GetKeyUp(SDL_Keycode keyCode);

	private:
		std::vector<SDL_Keycode>keys;
	};
}