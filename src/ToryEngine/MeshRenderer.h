#pragma once
#include <memory>

#include "Component.h"

namespace toryengine
{
	class VertexArray;
	class ShaderProgram;

	class MeshRenderer
	{
	public:
		void OnInit();
		//void SetMesh(std::weak_ptr<Mesh> mesh)
		//std::shared_ptr<Mesh> GetMesh();
		//std::shared_ptr<Material> GetMaterial();
	private:
		void OnDraw();

		//std::weak_ptr<Mesh> mesh;
		//std::shared_ptr<Material> material;
	};
}