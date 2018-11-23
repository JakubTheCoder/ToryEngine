#pragma once
#include <vector>
#include <SDL2/SDL.h>
namespace toryengine
{
	class Keyboard
	{
	public:
		//std::vector<SDL_Keycode> GetKeys() { return keys; }
		//bool GetKey(SDL_Keycode keyCode);
		static bool IsKeyDown(SDL_Keycode keyCode);
		//bool GetKeyUp(SDL_Keycode keyCode);

		static std::vector<SDL_Keycode>keys;
	private:

	};
	
}