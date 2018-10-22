#pragma once
#include <memory>
#include <vector>

#include "Component.h"

//Object = Entity

//Multiple components ???
//Do we need pragma once?
namespace toryengine
{
	class Root;	

	class Object
	{
		friend class Root; //Friend allows a class to access the private and protected variables of this class
	public:
		std::shared_ptr<Root> GetRoot();	//Go to the root, allows to interact with other objects easier.
		template <typename T> std::shared_ptr<T> GetComponent();	//template class since we dont know what type the component will be

		//Allows the constructor to set different vars, for example Make player. Make player in red team. Make player in red team a wizard.
		template <typename T> std::shared_ptr<T> AddComponent();

		template <typename T, typename A> std::shared_ptr<T> AddComponent(A a);

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

		bool begin; //start unity equiv
	};
}