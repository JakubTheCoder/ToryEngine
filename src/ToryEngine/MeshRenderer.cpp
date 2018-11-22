#include <iostream>
#include <glm/ext.hpp>
#include <SDL2/SDL.h>

#include "MeshRenderer.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ShaderProgram.h"
#include "Root.h"
#include "Object.h"
#include "Transform.h"
#include "Mesh.h"
#include "Camera.h"

namespace toryengine
{
	void MeshRenderer::OnInit()
	{
		shader = std::make_shared<ShaderProgram>("../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
		lightKeyShader = std::make_shared<ShaderProgram>("../resources/shaders/lightkeypass.vert","../resources/shaders/lightkeypass.frag");
		nullShader = std::make_shared<ShaderProgram>("../resources/shaders/nullpass.vert","../resources/shaders/nullpass.frag");
		blurShader = std::make_shared<ShaderProgram>("../resources/shaders/blur.vert","../resources/shaders/blur.frag");
		mergeShader = std::make_shared<ShaderProgram>("../resources/shaders/mergepass.vert","../resources/shaders/mergepass.frag");
	}

	void MeshRenderer::OnDraw()
	{
		// model mat4 from transform...
		shader->SetUniform("in_Model", GetObject()->GetComponent<Transform>()->GetMatrix());

		// camera's transform (and inverse) 

		shader->SetUniform("in_View", glm::inverse(GetRoot()->GetCurrentCamera()->GetComponent<Transform>()->GetMatrix()));
		//Make camera object Get view matrix 

		// from screen
		shader->SetUniform("in_Projection", GetRoot()->GetCurrentCamera()->GetComponent<Camera>()->GetProjectionMatrix());		//WIDTH / HEIGHT
		//Get camera projection matrix
		//shape = GetMesh();
		shader->Draw(mesh.lock()->GetShape());
	}

	void MeshRenderer::SetTexture(std::weak_ptr<Texture> _texture)
	{
		shader->SetUniform("in_Texture", _texture.lock());

	}

	void MeshRenderer::SetMesh(std::weak_ptr<Mesh> _mesh)
	{
		mesh = _mesh;
	}


}