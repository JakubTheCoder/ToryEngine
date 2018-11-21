#pragma once
#include <memory>

#include "Component.h"

namespace toryengine
{
	class VertexArray;
	class ShaderProgram;
	class Mesh;
	class Texture;
	class Camera;
	class Root;
	class MeshRenderer : public Component
	{
	public:
		void OnInit();

		void SetMesh(std::weak_ptr<Mesh> _mesh);
		std::shared_ptr<Mesh> GetMesh() { return mesh.lock(); }

		void SetTexture(std::weak_ptr<Texture> _texture);

		//std::shared_ptr<Material> GetMaterial();
	private:
		void OnDraw();

		//std::shared_ptr<VertexArray> shape;
		std::shared_ptr<ShaderProgram> shader;
		std::weak_ptr<Mesh> mesh;
		std::weak_ptr<Texture> texture;
		std::weak_ptr<Root> root;
		//std::shared_ptr<Material> material;
	};
}