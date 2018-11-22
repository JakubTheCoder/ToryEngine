#pragma once 
#include <glm/glm.hpp>
#include <vector>

#include "Component.h"
//#include "Root.h"

//include tribox C file.
namespace toryengine
{
	class BoxCollider;
	class MeshCollider;
	class Root;

	class Collider :public Component
	{
	public:
		//bool TriBoxCollision(glm::vec3 boxCentre, glm::vec3 boxHalfSize, Triangle t);//Faces from mesh);
		//bool BoxCollision(std::vector<std::shared_ptr<toryengine::Object>> boxOutput);//Box from 
		void OnUpdate();

	private:
		std::weak_ptr<Root> root;
	};
}