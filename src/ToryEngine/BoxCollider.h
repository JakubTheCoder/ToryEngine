#pragma once 
#include <glm/glm.hpp>
#include "Collision.h"
namespace toryengine
{
	class BoxCollider : public Collision
	{
	public:

	private:

		glm::vec3 size;
	};
}