#pragma once
#include <memory>
#include <vector>

#include "Collider.h"
namespace toryengine
{
	class Mesh;
	class VertexArray;

	class MeshCollider
	{
	public:
		std::shared_ptr<Mesh> GetMesh();
		std::vector<std::shared_ptr<Triangle>> GetShape();// {faces = mesh.lock()->GetShape(); }

	private:
		std::weak_ptr<Mesh> mesh;	//for faces
		//std::vector<std::shared_ptr<Triangle>>faces;
	};
}