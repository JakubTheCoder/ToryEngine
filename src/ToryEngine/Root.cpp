#include <GL/glew.h>
#include <algorithm>

#include "Root.h"
#include "Object.h"
#include "Transform.h"

#define WINDOW_WIDTH 800	//changes the words WINDOW_WIDTH to 800, no int or memory required to store this
#define WINDOW_HEIGHT 600
namespace toryengine
{
	std::shared_ptr<Root> Root::Initalize()
	{	
		//rtn
		//cant have constructor to itself
		std::shared_ptr<Root> temp = std::make_shared<Root>();	//makes temp a shared pointer
		temp->running = false;	//game loop is false 
		temp->rootSelf = temp;	//sets temp to itself since constructor can't do this
		temp->resources = std::make_shared<toryengine::Resources>();

		if (SDL_Init(SDL_INIT_VIDEO) < 0)	//Makes sure SDL initalises
		{
			throw std::exception();
		}

		temp->window = SDL_CreateWindow("Tory Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,	//Creates a window 
			WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

		if (!SDL_GL_CreateContext(temp->window))	//makes sure window is made
		{
			throw std::exception();
		}

		if (glewInit() != GLEW_OK)	//makes sure GLEW initalises
		{
			throw std::exception();
		}

		return temp;
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
				(*i)->Update(); //object ticks() 
			}

			//CLEAR SCREEN
			glClearColor(0.0f, 0.0f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			//DRAW OBJECTS
			for (std::vector<std::shared_ptr<Object>>::iterator i = objects.begin(); i != objects.end(); i++)
			{
				(*i)->Draw(); //Object Draws //Iterator is a pointer so we have to de reference that to access data
			}

			SDL_GL_SwapWindow(window);	//swap buffer
		}

	}

	void Root::Stop()
	{
		running = false;
	}

	std::shared_ptr<Object> Root::AddObject()
	{
		std::shared_ptr<Object> temp = std::make_shared<Object>();	//make a temp shared pointer

		objects.push_back(temp);	//push it back into the objects vector
		temp->objectSelf = temp;	//make itself temp
		temp->root = rootSelf;		//make root what it is.
		//temp->resources?????
		temp->AddComponent<Transform>();
		return temp;

	}
}