#pragma once
#include <memory>
#include <vector>
#include <SDL2/SDL.h>
#include <AL/al.h>
#include <AL/alc.h>

#include "NonCopyable.h"
#include "Object.h"

namespace toryengine
{

	//allows root to access these classes
	class Object;
	class Resources;
	class Environment;
	class Camera;
	class Keyboard;

	/*!
	Root is  the base class of the engine, it is used to update Object and any Component attached to it.
	All Objects that are made are added to the vector of objects inside of root,
	so that Objects or Components can access other objects allowing them to interact with eachother
	by going up the heirarchy.
	*/

	class Root :private NonCopyable
	{

	public:
		///<Initializes Root. It has to be called when Root is made. Initalize sets up any dependancies like SDL, Glew and OpenAL
		static std::shared_ptr<Root> Initalize();	

		void Start();	///<Main loop. Updates and draws all Objects as well as adds Keyboard input
		void Stop();	///<Stops the program.

		std::shared_ptr<Object> AddObject();	///<Adds an Object to a vector to keep track and update
		std::shared_ptr<Resources> GetResources() { return resources; }	///<Grants access to Resources manager
		std::shared_ptr<Environment> GetEnvironment() { return environment; }	///<Grants access to environment(delta time)
		std::shared_ptr<Object> GetCurrentCamera() { return currentCamera; }	///<Grants access to current camera that is displaying
		void SetCurrentCamera(std::shared_ptr<Object> _camera) { currentCamera = _camera; }	///<Sets a camera to current to view through camera

		//!\brief Template class that lets you check if a object has a certain component
		/*!
		To use this function a vector of objects needs to be made and passed in as the parameter which will add all the objects with said component to the vector:	
		std::vector<std::shared_ptr<aComponentType> objectsWithComponent;
		*/
		
		template <typename T> 
		void GetObjectsWithComponent(std::vector<std::shared_ptr<Object>>& output)	
		{
			//output.clear();
			for (size_t i= 0; i < objects.size(); i++)
			{
				if (objects.at(i)->HasComponent<T>())
				{
					output.push_back(objects.at(i));
				}
			}
		}

	private:
		std::weak_ptr<Root> rootSelf;	//weak pointer for reference

		std::vector<std::shared_ptr<Object>> objects;	//Vector of all objects

		//Other stuff Root has to access
		std::shared_ptr<Resources> resources;	//loading in textures / models / shaders
		std::shared_ptr<Environment> environment;	//delta time

		std::shared_ptr<Object> currentCamera;	//Current camera


		bool running;	//game loop bool
		SDL_Window* window;	
		ALCdevice* device;
		ALCcontext* context;
	};
}