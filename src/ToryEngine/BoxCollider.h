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

		glm::vec3 GetSize();

		bool isBoxColliding() { return isColliding; }
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