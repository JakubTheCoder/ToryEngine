#pragma once 
#include <glm/glm.hpp>
#include <vector>

#include "Collider.h"
#include <iostream>	//TEMP DELETE

namespace toryengine
{
	class Root;

	class BoxCollider : public Collider
	{
		friend class Object;

	public:
		void SetSize(glm::vec3 _size) { size = _size; }
		glm::vec3 GetSize() { return size; }

		void Test() {  std::cout << "Hello"; }

		bool isBoxColliding() { return isColliding; }
		void OnUpdate();

		//std::shared_ptr<Root> GetRoot();

	private:
		std::weak_ptr<Root> root;
		glm::vec3 size;
		bool isColliding;
	};
}