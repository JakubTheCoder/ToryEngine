#pragma once
#include <memory>

namespace toryengine
{
	class Root;
	class Object;
	class Resources;
	/*!
		Component class allows to create components to attach to a Object. These Components make the behaviour of a Object
	*/
	class Component
	{
		friend class Object; //Friend allows a class to access the private and protected variables of this class

	public:
		virtual ~Component() {}
		std::shared_ptr<Object> GetObject() { return object.lock(); }	///<Gets the object that the Component is attached to
		std::shared_ptr<Root> GetRoot();	///<Gets pointer to root (by getting object - getting root) to go up hierarchy
		std::shared_ptr<Resources> GetResources();	///<Gets Resource Manager to load in different Resources

		bool isEnabled() { return enabled; }	///<Checks if a component is enabled

		void SetEnabled(bool isEnabled) { enabled = isEnabled; }	///< Sets component to be enabled / disabled based on parameter bool
	private:
		std::weak_ptr<Object> object;	//weak ptr to go up hierarchy
		std::weak_ptr<Root> root;
		bool began;
		bool enabled = true;
		virtual void OnInit() { }	// on init
		virtual void OnBegin() { }	// on begin
		virtual void OnUpdate() { }	//update (on tick)
		virtual void OnDraw() { }	//draw


	};
}