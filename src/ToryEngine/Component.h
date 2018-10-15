#include <memory>

namespace toryengine
{
	class Root;
	class Object;

	class Component
	{
		friend class Object; ////Friend allows a class to access the private and protected variables of this class

	public:
		virtual ~Component() {}
		std::shared_ptr<Object> GetObject() { return object.lock(); }
		std::shared_ptr<Root> GetRoot();
		//Keyboard / Env / Resources

	private:
		std::weak_ptr<Object> object;	//weak ptr to go up hierarchy
		virtual void OnInit() { }	// on init
		virtual void OnBegin() { }	// on begin ? we might not need this??
		virtual void OnUpdate() { }	//update
		virtual void OnDisplay() { }	//display

	};
}