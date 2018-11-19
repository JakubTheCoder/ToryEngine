#pragma once 

#include <glm/glm.hpp>
#include "Component.h"

//include tribox C file.
namespace toryengine
{
	extern "C"
	{
		int triBoxOverlap(float boxcenter[3], float boxhalfsize[3], float triverts[3][3]);
	}

	struct Triangle;

	class Collider :public Component
	{
	public:
		//bool TriBoxCollision(glm::vec3 boxCentre, glm::vec3 boxHalfSize, Triangle t);
		//bool BoxCollision();

	private:

	};
}