#pragma once
#include <vector>
#include <SDL2/SDL.h>
namespace toryengine
{
	/*!
		Keyboard Input class that stores all the keys that have been pressed
	*/
	class Keyboard
	{
	public:
		Keyboard() {}
		~Keyboard() {}
		static bool IsKeyDown(SDL_Keycode keyCode);	///<checks if a certain button was pressed
		static std::vector<SDL_Keycode>keys;	///< public vecotr of keys that are being pressed so that they can be accessed from anywhere
	private:

	};
	
}