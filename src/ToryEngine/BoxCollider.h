#pragma once 
#include <glm/glm.hpp>
#include <vector>

#include "Component.h"
namespace toryengine
{
	class Root;
	class MeshRenderer;

	class BoxCollider : public Component
	{
		friend class Object;

	public:
		//BoxCollider();
		void SetSize();
		//void SetSize(glm::vec3 minPoint,glm::vec3 maxPoint);
		glm::vec3 GetSize();
		glm::vec3 GetMinSize();
		glm::vec3 GetMaxSize();
		bool isBoxColliding() { return isColliding; }
		bool isCollidingWith(std::shared_ptr<Object> other);
		void OnUpdate();
		void OnInit();

	private:
		//std::weak_ptr<Mesh> mesh;
		std::weak_ptr<Root> root;
		glm::vec3 sizeMin;
		glm::vec3 sizeMax;
		bool isColliding;
	};
}