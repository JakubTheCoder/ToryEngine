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
		std::shared_ptr<Root> getRoot();	//Go to the root, allows to interact with other objects easier.
		template <typename T> std::shared_ptr<T> getComponent();	//template class since we dont know what type the component will be

		//add multiple components?
		template <typename T> 
		std::shared_ptr<T> addComponent<T>();

		/*template <typename T, typename A> 
		std::shared_ptr<T> addComponent<T>(A a);

		template <typename T, typename A, typename B>
		std::shared_ptr<T> addComponent<T>(A a, B b);

		template <typename T, typename A, typename B, typename C> 
		std::shared_ptr<T> addComponent<T>(A a, B b, C c);*/

	private:
		bool begin; //start unity equiv
		std::vector <std::shared_ptr<Component>> components;
		std::weak_ptr<Root> root;

		void Update();
		void Draw();
	};
}