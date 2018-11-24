#include "Keyboard.h"
#include <iostream>
namespace toryengine
{
	std::vector<SDL_Keycode> Keyboard::keys;


	bool Keyboard::IsKeyDown(SDL_Keycode _key)
	{
		for (size_t i = 0; keys.size(); i++)
		{
			if (keys.at(i) == _key)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		//return false;
	}
}
