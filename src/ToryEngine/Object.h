#pragma once
#include <memory>
#include <vector>

#include "Component.h"

//Object = Entity

//Do we need pragma once?
namespace toryengine
{
	class Root;	

	/*!
	Acts as base object to attach components to.
	*/
	class Object
	{
		friend class Root; //Friend allows a class to access the private and protected variables of this class
	public:
		std::shared_ptr<Root> GetRoot();	///< Go to the root, allows to interact with other objects easier.

		template <typename T> std::shared_ptr<T> GetComponent()	//template class since we dont know what type the component will be
		{
			for (size_t i = 0; i < components.size(); i++)	//go thorugh all components of a object
			{
				//attempts to convert back to original component (T) if fails test will be NULL, therefore it is not the component we are looking for
				std::shared_ptr<T> test = std::dynamic_pointer_cast<T>(components.at(i));	//Dynamic casts converts pointers to classes up/ down heirarchy 
				if (test)
				{
					return test;
				}
			}
			throw std::exception();//thorw exeption if we couldn't find object

		}
		//Allows the constructor to set different vars, for example Make player. Make player in red team. Make player in red team a wizard.
		template <typename T> std::shared_ptr<T> AddComponent()
		{
			std::shared_ptr<T> temp = std::make_shared<T>();
			temp->object = objectSelf;
			temp->began = false;
			
			components.push_back(temp);
			temp->OnInit();
			return temp;
		}
		template <typename T, typename A> std::shared_ptr<T> AddComponent(A a)
		{
			std::shared_ptr<T> temp = std::make_shared<T>();
			temp->object = objectSelf;
			temp->began = false;
			components.push_back(temp);

			//temp->resources = root->resources;
			temp

			temp->OnInit(a);

			return temp;
		}

		/*
		template <typename T, typename A, typename B>
		std::shared_ptr<T> addComponent<T>(A a, B b);

		template <typename T, typename A, typename B, typename C> 
		std::shared_ptr<T> addComponent<T>(A a, B b, C c);
		*/

	private:
		std::weak_ptr<Object> objectSelf;
		std::weak_ptr<Root> root;
		std::vector <std::shared_ptr<Component>> components;


		void Update();
		void Draw();

		//bool begin; 
	};
}