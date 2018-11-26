#pragma once
#include <memory>
#include <vector>

#include "Component.h"

namespace toryengine
{
	/*!
		Object is a class that allows you to create game objects to attach components to. 
	*/
	class Object

	{
		friend class Root; //Friend allows a class to access the private and protected variables of this class
	public:
		std::shared_ptr<Root> GetRoot();	///< Get Access to Root, allowing to go up hierarchy

		//!Template class that allows you to get a component of any type
		template <typename T> 
		std::shared_ptr<T> GetComponent()
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

		//!Template class that allows you to check if a object has a specific componenet
		template <typename T>
		bool HasComponent()	
		{
			for (size_t i = 0; i < components.size(); i++)	//go thorugh all components of a object
			{
				std::shared_ptr<T> test = std::dynamic_pointer_cast<T>(components.at(i));
				if (test)
				{
					return true;
				}
				
			}
			return false;

		}
		//!Allows you to add a component to a object of any type
		template <typename T>
		std::shared_ptr<T> AddComponent()	
		{
			std::shared_ptr<T> temp = std::make_shared<T>();
			temp->object = objectSelf;
			temp->began = false;
			temp->root = root;

			components.push_back(temp);
			temp->OnInit();
			return temp;
		}

		template <typename T, typename A>
		std::shared_ptr<T> AddComponent(A _a)	///<allows the constructor to set different vars, for example  Make player in red team etc.
		{
			std::shared_ptr<T> temp = std::make_shared<T>();
			temp->object = objectSelf;
			temp->began = false;
			temp->root = root;

			components.push_back(temp);

			temp->OnInit(_a);

			return temp;
		}
	private:
		std::weak_ptr<Object> objectSelf;
		std::weak_ptr<Root> root;
		std::vector <std::shared_ptr<Component>> components;


		void Update();
		void Draw();

		//bool begin; 
	};
}