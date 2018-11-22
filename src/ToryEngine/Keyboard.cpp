#include "Keyboard.h"

namespace toryengine
{
	bool Keyboard::GetKeyDown(SDL_Keycode key)
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
		return false;
	}
}