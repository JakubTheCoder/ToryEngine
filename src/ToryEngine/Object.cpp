#include "Object.h"

namespace toryengine
{
	std::shared_ptr<Root> Object::GetRoot()
	{
		return root.lock();	//creates a shared ptr to Root (to go up hierarchy)
	}
	
	//template <typename T> 
	//std::shared_ptr<T> Object::GetComponent()	
	//{
	//	for (size_t i = 0; i < components.size()i++)	//go thorugh all components of a object
	//	{
	//		//attempts to convert back to original component (T) if fails test will be NULL, therefore it is not the component we are looking for
	//		std::shared_ptr<T> test = std::dynamic_pointer_cast<T>(components.at(i));	//Dynamic casts converts pointers to classes up/ down heirarchy 
	//		if (test)
	//		{
	//			return test;
	//		}
	//	}

	//	throw std::exeption(); //thorw exeption if we couldn't find object
	//}	 

	//template <typename T>
	//std::shared_ptr<T> Object::AddComponent()
	//{
	//	//Creates new smart pointer of T, 
	//	//sets itself to itself (inside a smart pointer)
	//	std::shared_ptr<T> temp = std::make_shared<T>();
	//	temp->object = objectSelf;
	//	temp->began = false;
	//	components.push_back(temp);

	//	temp->OnInit();
	//	return temp;
	//}

	////Extra templates we might not need
	//
	//template <typename T, typename A> 
	//std::shared_ptr<T> Object::AddComponent(A a)
	//{
	//	std::shared_ptr<T> temp = std::make_shared<T>();
	//	temp->object = objectSelf;
	//	temp->began = false;
	//	components.push_back(temp);

	//	temp->OnInit(a);

	//	return temp;
	//}

	/*
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
		//Go Through all the components on a object and update them. 
		for (std::vector<std::shared_ptr<Component>>::iterator i = components.begin();i != components.end(); i++)
		{
			if (!(*i)->began)
			{
				(*i)->OnBegin();
				(*i)->began = true;
			}
			(*i)->OnUpdate();

		}
	}

	void Object::Draw()
	{
		//Go through all components and draw them
		for (std::vector<std::shared_ptr<Component>>::iterator i = components.begin(); i != components.end(); i++)
		{
			(*i)->OnDraw();
		}
	}
}