#pragma once 

#include <glm/glm.hpp>
#include "Component.h"
#include <vector>

//include tribox C file.
namespace toryengine
{
	extern "C"
	{
		int triBoxOverlap(float boxcenter[3], float boxhalfsize[3], float triverts[3][3]);
	}

	//struct Triangle;

	class Collider :public Component
	{
	public:
		bool TriBoxCollision(glm::vec3 boxCentre, glm::vec3 boxHalfSize);//Faces from mesh);
		bool BoxCollision();//Box from 
		void OnTick()
		{
			std::vector<std::shared_ptr<toryengine::Object>> output;
			root->GetObjectsWithComponent<MeshCollider>(output);
		}
		//get a list of all ocmponentes
		//try to collide with it, first AABB
		//Those that colide do a triangle box intercent using triBoxOVerLap
	private:

	};
}