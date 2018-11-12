#pragma once
#include <memory>

namespace toryengine
{
	class Root;
	class Object;
	class Resources;

	class Component
	{
		friend class Object; //Friend allows a class to access the private and protected variables of this class

	public:
		virtual ~Component() {}
		std::shared_ptr<Object> GetObject() { return object.lock(); }
		std::shared_ptr<Root> GetRoot();
		std::shared_ptr<Resources> GetResources() { return resources.lock(); }
		//Keyboard / Env / Resources

	private:
		std::weak_ptr<Object> object;	//weak ptr to go up hierarchy
		std::weak_ptr<Resources> resources;
		bool began;

		virtual void OnInit() { }	// on init
		virtual void OnBegin() { }	// on begin
		virtual void OnUpdate() { }	//update
		virtual void OnDraw() { }	//draw


	};
}