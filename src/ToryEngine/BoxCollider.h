#pragma once 
#include <glm/glm.hpp>
#include <vector>
#include "Collision.h"
//#include "Root.h"
namespace toryengine
{
	
	class Root;
	class BoxCollider : public Collision
	{
	public:
		friend class Object;
		void SetSize(glm::vec3 _size) { size = _size; }
		glm::vec3 GetSize() { return size; }
		void onTick();
		std::shared_ptr<Root> GetRoot();
	private:
		std::weak_ptr<Root> root;
		glm::vec3 size;
		bool isColliding;
	};
}