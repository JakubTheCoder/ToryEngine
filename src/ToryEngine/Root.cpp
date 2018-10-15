#include <GL/glew.h>
#include <algorithm>

#include "Root.h"
#include "Object.h"

//EXPLAIN RTN?
namespace toryengine
{
	std::shared_ptr<Root> Root::initalize()
	{	
		//rtn
		//cant have constructor to itself so you okay
		if (SDL_Init(SDL_INIT_VIDEO) < 0)	//Makes sure SDL initalises
		{
			throw std::exception();
		}

		//rtn window

		//if SDL GL Create context

		if (glewInit() != GLEW_OK)	//makes sure GLEW initalises
		{
			throw std::exception();
		}
		//return rtn
	}

	void Root::Start()
	{
		running = true; //game loop bool

		while (running)	//= true
		{
			SDL_Event event = { 0 }; //allows us to have inputs

			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					running = false; //Turns program off
				}
			}

			//UPDATE OBJECTS
			
			for (std::vector<std::shared_ptr<Object> >::iterator i = objects.begin(); i != objects.end(); i++)	//go through all objects in object vector
			{
				//object ticks() 
			}
			//ranged based loop (for each) makes for loop a lot shorter 
			for each (std::shared_ptr<Object> o in objects) //(object var in collection_to_loop)	<syntax/ For each object in loop {do this}
			{
				//Object ticks//
			}
			//CLEAR SCREEN
			glClearColor(0.0f, 0.0f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			//DRAW OBJECTS
			for (std::vector<std::shared_ptr<Object>>::iterator i = objects.begin(); i != objects.end(); i++)
			{
				//Object Draws ()
			}

			SDL_GL_SwapWindow(window);	//swap buffer
		}

	}

	void Root::Stop()
	{
		running = false;
	}

	std::shared_ptr<Object> Root::addObject()
	{
		std::shared_ptr<Object> temp = std::make_shared<Object>();//rtn
		objects.push_back(temp);

		//rtn?
		//rtn rtn ;)
	}
}