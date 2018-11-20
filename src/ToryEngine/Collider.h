#pragma once 

#include <glm/glm.hpp>
#include "Component.h"
#include <vector>
#include "Root.h"

//include tribox C file.
namespace toryengine
{
	extern "C"
	{
		int triBoxOverlap(float boxcenter[3], float boxhalfsize[3], float triverts[3][3]);
	}

	struct Triangle;
	class BoxCollider;
	class MeshCollider;
	class Root;

	class Collider :public Component
	{
	public:
		bool TriBoxCollision(glm::vec3 boxCentre, glm::vec3 boxHalfSize, Triangle t);//Faces from mesh);
		//bool BoxCollision(std::vector<std::shared_ptr<toryengine::Object>> boxOutput);//Box from 
		void OnTick();

		//get a list of all ocmponentes
		//try to collide with it, first AABB
		//Those that colide do a triangle box intercent using triBoxOVerLap
	private:
		std::weak_ptr<Root> root;
		//bool isBoxColliding;
	};
}