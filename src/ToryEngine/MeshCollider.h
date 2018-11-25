#pragma once
#include <memory>
#include <vector>

#include "VertexArray.h"
namespace toryengine
{
	class Root;
	class Mesh;
	class VertexArray;
	class BoxCollider;

	extern "C"
	{
		int triBoxOverlap(float boxcenter[3], float boxhalfsize[3], float triverts[3][3]);
	}
	class MeshCollider : public Component
	{
		friend class Object;
	public:
		std::shared_ptr<Mesh> GetMesh();
		std::vector<std::shared_ptr<Triangle>> GetShape();

		void OnUpdate();
	private:
		std::weak_ptr<Root> root;
		std::weak_ptr<Mesh> mesh;	//for faces
		bool isTriBoxColliding;
	};
}