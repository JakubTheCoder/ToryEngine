#include "Object.h"

namespace toryengine
{
	std::shared_ptr<Root> Object::getRoot()
	{
		return root.lock();	//creates a shared ptr to Root (to go up hierarchy)
	}
	
	template <T> 
	std::shared_ptr<T> Object::getComponent()
	{
	}

	template <typename T>
	std::shared_ptr<T> addComponent<T>()
	{
		//rtn again?
	}

	template <typename T, typename A> 
	std::shared_ptr<T> addComponent<T>(A a)
	{
	}

	template <typename T, typename A, typename B> 
	std::shared_ptr<T> addComponent<T>(A a, B b)
	{
	}

	template <typename T, typename A, typename B, typename C> 
	std::shared_ptr<T> addComponent<T>(A a, B b, C c)
	{
	}

	void Object::Update()
	{
		//for / for each loop to update all components 
	}

	void Object::Draw()
	{
		//for / for each loop to draw all components 
	}
}