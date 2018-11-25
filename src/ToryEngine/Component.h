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
		std::shared_ptr<Resources> GetResources();
		//Keyboard / Env / Resources
		bool isEnabled() { return enabled; }
		void SetEnabled(bool isEnabled) { enabled = isEnabled; }
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