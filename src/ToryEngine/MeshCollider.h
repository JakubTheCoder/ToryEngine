#pragma once
#include <memory>

#include "Collider.h"
namespace toryengine
{
	class Mesh;

	class MeshCollider
	{
	public:

	private:
		std::weak_ptr<Mesh> Mesh;	//for faces
	};
}