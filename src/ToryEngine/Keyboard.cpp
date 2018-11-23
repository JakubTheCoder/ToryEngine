#include "Keyboard.h"

namespace toryengine
{
	std::vector<SDL_Keycode> Keyboard::keys;


	bool Keyboard::IsKeyDown(SDL_Keycode _key)
	{
		for (int i = 0; keys.size(); i++)
		{
			if (keys.at(i) == _key)
			{
				return true;
			}
		}
		return false;
	}
/*	bool Keyboard::GetKeyDown(SDL_Keycode key)
	{
		for (size_t i = 0; i < keys.size(); i++)
		{
			if (keys.at(i) == key)
			{
				return true;
			}
		}
		return false;
	}

	bool Keyboard::GetKeyUp(SDL_Keycode key)
	{
		for (size_t i = 0; i < keys.size(); i++)
		{
			if (keys.at(i) != key)
			{
				return true;
			}
		}

	}
	*/
}
