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
		for (size_t i = 0; i < components.size()i++)	//go thorugh all components of a object
		{
			std::shared_ptr<T> test = std::dynamic_pointer_cast<T>(components.at(i));	//attempts to convert back to original component (T) if fails test will be NULL, therefore it is not the component we are looking for
			//Dynamic casts converts pointers to classes up/ down heirarchy 
			if (test)
			{
				return test;
			}
		}

		throw std::exeption(); //thorw exeption if we couldn't find object
	}

	template <typename T>
	std::shared_ptr<T> addComponent<T>()
	{
		//Creates new smart pointer of T, 
		//sets itself to itself (inside a smart pointer)
		std::shared_ptr<T> temp = std::make_shared<T>();
		temp->object = objectSelf;

	}
	//Extra templates we might not need
	/*
	//template <typename T, typename A> 
	//std::shared_ptr<T> addComponent<T>(A a)
	//{
	//}

	//template <typename T, typename A, typename B> 
	//std::shared_ptr<T> addComponent<T>(A a, B b)
	//{
	//}

	//template <typename T, typename A, typename B, typename C> 
	//std::shared_ptr<T> addComponent<T>(A a, B b, C c)
	//{
	//}
	*/

	void Object::Update()
	{
		//for / for each loop to update all components 
	}

	void Object::Draw()
	{
		//for / for each loop to draw all components 
	}
}