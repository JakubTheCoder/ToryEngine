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
		//std::shared_ptr<VertexBuffer> positions = std::make_shared<VertexBuffer>();
		//positions->Add(glm::vec3(0.0f, 0.5f, 0.0f));
		//positions->Add(glm::vec3(-0.5f, -0.5f, 0.0f));
		//positions->Add(glm::vec3(0.5f, -0.5f, 0.0f));

		//std::shared_ptr<VertexBuffer>texCoords = std::make_shared<VertexBuffer>();
		//texCoords->Add(glm::vec2(0.5f, 0.0f));
		//texCoords->Add(glm::vec2(0.0f, 1.0f));
		//texCoords->Add(glm::vec2(1.0f, 1.0f));
		////std::shared_ptr<VertexBuffer> colors = std::make_shared<VertexBuffer>();
		////colors->Add(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
		////colors->Add(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
		////colors->Add(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

		//shape = std::make_shared<VertexArray>();
		//shape->SetBuffer("in_Position", positions);

		//shape->SetBuffer("in_TexCoord", texCoords);
		shader = std::make_shared<ShaderProgram>("../resources/shaders/simple.vert", "../resources/shaders/simple.frag");

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
		shader->Draw(*mesh.lock()->GetShape());
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