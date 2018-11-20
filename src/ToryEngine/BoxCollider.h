#pragma once 
#include <glm/glm.hpp>
#include <vector>
#include "Collider.h"

namespace toryengine
{
	//class Object;
	class Root;
	class BoxCollider : public Collider
	{
		friend class Object;

	public:
		void SetSize(glm::vec3 _size) { size = _size; }
		glm::vec3 GetSize() { return size; }

		void OnUpdate();

		//std::shared_ptr<Root> GetRoot();

	private:
		std::weak_ptr<Root> root;
		glm::vec3 size;
		bool isBoxColliding;
	};
}