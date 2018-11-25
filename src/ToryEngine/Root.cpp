#include <GL/glew.h>
#include <algorithm>

#include "Root.h"
#include "Transform.h"
#include "Resources.h"
#include "Environment.h"
#include "Camera.h"
#include "Keyboard.h"
#include <iostream>
#define WINDOW_WIDTH 800	
#define WINDOW_HEIGHT 600

namespace toryengine
{
	void Root::Start()
	{
		running = true; //game loop bool

		//
		//glm::vec3 angle = glm::vec3(0.0f, 1.0f, 0.0f);

		float lastTime = SDL_GetTicks();
		float idealTime = 1.0f / 60.0f;

		while (running)	//= true
		{
			float time = SDL_GetTicks();
			float diff = time - lastTime;
			environment->SetDeltaTime(diff / 1000.0f);

			SDL_Event event = { 0 }; //allows us to have inputs
			while (SDL_PollEvent(&event))
			{
				switch (event.type)
				{
				case SDL_QUIT:
					running = false;
					break;
					
				case SDL_KEYDOWN:
					Keyboard::keys.push_back(event.key.keysym.sym);
					break;

				case SDL_KEYUP:
					for (int i = 0; i < Keyboard::keys.size(); i++)
					{
						if (Keyboard::keys.at(i) == event.key.keysym.sym)
						{
							Keyboard::keys.erase(Keyboard::keys.begin() + i);
							i--;
						}
					}
					break;
				}

			}

			//CAMERA STUFF
			std::vector<std::shared_ptr<Object>> cameras;
			rootSelf.lock()->GetObjectsWithComponent<Camera>(cameras);

			//for (size_t i = 0; i < cameras.size(); i++)
			//{
			//	SetCurrentCamera(cameras.at(i));
			//	cameras.at(i)->Draw();
			//}

			//UPDATE OBJECTS
			for (std::vector<std::shared_ptr<Object> >::iterator i = objects.begin(); i != objects.end(); i++)	//go through all objects in object vector
			{
				//(*i)->GetComponent<Transform>()->Rotate(angle);
				(*i)->Update(); //object ticks() 
			}

			//CLEAR SCREEN
			glClearColor(0.0f, 0.0f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glEnable(GL_CULL_FACE);
			glEnable(GL_DEPTH_TEST);
			//DRAW OBJECTS
			for (std::vector<std::shared_ptr<Object>>::iterator i = objects.begin(); i != objects.end(); i++)
			{
				(*i)->Draw(); //Object Draws //Iterator is a pointer so we have to de reference that to access data
			}

			SDL_GL_SwapWindow(window);	//swap buffer

			if (idealTime > environment->GetDeltaTime())
			{
				//Sleep for remaning time
				SDL_Delay((idealTime - environment->GetDeltaTime())*1000.0f);
			}
			glDisable(GL_CULL_FACE);
			glDisable(GL_DEPTH_TEST);
		}
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	void Root::Stop()
	{
		running = false;
	}

	std::shared_ptr<Root> Root::Initalize()
	{
		//cant have constructor to itself
		std::shared_ptr<Root> temp = std::make_shared<Root>();	//makes temp a shared pointer
		temp->running = false;	//game loop is false 
		temp->rootSelf = temp;	//sets temp to itself since constructor can't do this

		//Make pointers to things that work from Root
		temp->resources = std::make_shared<Resources>();
		temp->environment = std::make_shared<Environment>();

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

		temp->device = alcOpenDevice(NULL);
		if (!temp->device)
		{
			throw std::exception();
		}
		//temp->context = alcCreateContext(temp->device, NULL);
		temp->context = alcCreateContext(temp->device, NULL);
		if (!temp->context)
		{
			alcCloseDevice(temp->device);
			throw std::exception();
		}

		if (!alcMakeContextCurrent(temp->context))
		{
			alcDestroyContext(temp->context);
			alcCloseDevice(temp->device);
			throw std::exception();
		}
		return temp;
	}
	std::shared_ptr<Object> Root::AddObject()
	{
		std::shared_ptr<Object> temp = std::make_shared<Object>();	//make a temp shared pointer

		objects.push_back(temp);	//push it back into the objects vector
		temp->objectSelf = temp;	//make itself temp
		temp->root = rootSelf;		//make root what it is.
		temp->AddComponent<Transform>();
		return temp;

	}
}