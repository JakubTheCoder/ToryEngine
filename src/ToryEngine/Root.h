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
		static std::shared_ptr<Root> initalize();	//static can be called anywhere to init Root
		~Root();			//???????? Do  I need this

		void Start();	//Main loop. runs all object updates etc
		void Stop();

		std::shared_ptr<Object> addObject();	//Adds a object to the vector

	private:
		//ENVIRNOMENT (Add all other things here as well)

		//Objects / Entities
		std::vector<std::shared_ptr<Object>> objects;	//Vector of all objects

		bool running;	//game loop bool
		SDL_Window* window;
	};
}