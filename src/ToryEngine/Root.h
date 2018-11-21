#pragma once
#include <memory>
#include <vector>
#include <SDL2/SDL.h>
#include <AL/al.h>
#include <AL/alc.h>

#include "NonCopyable.h"
#include "Object.h"
//ROOT = CORE

namespace toryengine	//Makes sure it uses the Tory Engine functions, even if user has same function names.
{

	//allows root to access these classes
	class Object;
	class Resources;
	class Environment;
	//class BoxCollider;
	class Camera;

	class Root :private NonCopyable
	{

	public:
		static std::shared_ptr<Root> Initalize();	//static can be called anywhere to init Root

		void Start();	//Main loop. runs all object updates etc
		void Stop();	//stops the program

		std::shared_ptr<Object> AddObject();	//Adds a object to the vector
		std::shared_ptr<Resources> GetResources() { return resources; }	//get a list of resources

		std::shared_ptr<Object> GetCurrentCamera() { return currentCamera; }
		void SetCurrentCamera(std::shared_ptr<Object> _camera) { currentCamera = _camera; }

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

		std::shared_ptr<Object> currentCamera;
		std::vector<std::shared_ptr<Object>> cameras;

		bool running;	//game loop bool
		SDL_Window* window;
		ALCdevice* device;
		ALCcontext* context;
	};
}