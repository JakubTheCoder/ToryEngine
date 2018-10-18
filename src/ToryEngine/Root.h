#pragma once
#include <memory>
#include <vector>

#include <SDL2/SDL.h>

//ROOT = CORE

namespace toryengine	//Makes sure it uses the Tory Engine functions, even if user has same function names.
{
	class Object;	//allow root to access object

	class Root //:private NonCopyable
	{
	public:
		static std::shared_ptr<Root> Initalize();	//static can be called anywhere to init Root

		void Start();	//Main loop. runs all object updates etc
		void Stop();	//stops the program

		std::shared_ptr<Object> AddObject();	//Adds a object to the vector

	private:
		std::weak_ptr<Root> rootSelf;	//weak pointer for reference


		//Objects / Entities
		std::vector<std::shared_ptr<Object>> objects;	//Vector of all objects
		//ENVIRNOMENT (Add all other things here as well)

		bool running;	//game loop bool
		SDL_Window* window;
	};
}