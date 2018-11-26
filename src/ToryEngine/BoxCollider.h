#pragma once 
#include <glm/glm.hpp>
#include <vector>

#include "Component.h"
namespace toryengine
{
	class Root;
	class MeshRenderer;
	/*!
		BoxCollider class that makes a collider around a object that is used for collision
	*/
	class BoxCollider : public Component
	{
		friend class Object;

	public:
		void SetSize();	///<Sets the size of the collider based on the smallest and biggest point of the mesh
		glm::vec3 GetMinSize();	///<Gets the minimum point of the collider (used for collision)
		glm::vec3 GetMaxSize();	///<Gets the maximum pooint of the collider (used for collision)
		bool isBoxColliding() { return isColliding; }	///<Returns true or false based on if there is a collision
		bool isCollidingWith(std::shared_ptr<Object> other);	///<Checks to see if collisions are happening between another specified object
		void OnUpdate();	///<Update function for box collider 
		void OnInit();	///<Initialisation function for box collider

	private:
		std::weak_ptr<Root> root;
		glm::vec3 sizeMin;
		glm::vec3 sizeMax;
		bool isColliding;
	};
}