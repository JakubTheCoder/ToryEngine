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

	/*!
		MeshRenderer class that takes care of drawing objects onto the screen
	*/
	class MeshRenderer : public Component
	{
	public:
		void OnInit();	///<Initialize function for Mesh Renderer

		void SetMesh(std::weak_ptr<Mesh> _mesh);	///<Makes the loaded in mesh to this component's mesh
		std::shared_ptr<Mesh> GetMesh() { return mesh.lock(); }	///<Returns pointer to mesh in this component

		void SetTexture(std::weak_ptr<Texture> _texture);	///<Sets a texture to the mesh 

		std::shared_ptr<ShaderProgram>GetShader() { return shader; }	///<Gets the normal shader 
	private:
		void OnDraw();

		std::shared_ptr<ShaderProgram> shader;
		std::shared_ptr<ShaderProgram> lightKeyShader;
		std::shared_ptr<ShaderProgram> nullShader;
		std::shared_ptr<ShaderProgram> blurShader;
		std::shared_ptr<ShaderProgram> mergeShader;

		std::weak_ptr<Mesh> mesh;
		std::weak_ptr<Texture> texture;
	};
}