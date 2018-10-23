#include <iostream>
#include <glm/ext.hpp>
#include <SDL2/SDL.h>
#include "MeshRenderer.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ShaderProgram.h"
#include "Object.h"
#include "Transform.h"

namespace toryengine
{
	void MeshRenderer::OnInit()
	{
		std::shared_ptr<VertexBuffer> positions = std::make_shared<VertexBuffer>();
		positions->Add(glm::vec3(0.0f, 0.5f, 0.0f));
		positions->Add(glm::vec3(-0.5f, -0.5f, 0.0f));
		positions->Add(glm::vec3(0.5f, -0.5f, 0.0f));

		std::shared_ptr<VertexBuffer> colors = std::make_shared<VertexBuffer>();
		colors->Add(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
		colors->Add(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
		colors->Add(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

		shape = std::make_shared<VertexArray>();
		shape->SetBuffer("in_Position", positions);
		shape->SetBuffer("in_Color", colors);

		shader = std::make_shared<ShaderProgram>("../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
	}

	void MeshRenderer::OnDraw()
	{
		// model mat4 from transform...
		shader->SetUniform("in_Model", GetObject()->GetComponent<Transform>()->GetMatrix());//glm::mat4(1.0f));

		// camera's transform (and inverse) 
		shader->SetUniform("in_View", glm::mat4(1.0f));

		// from screen
		shader->SetUniform("in_Projection",glm::perspective(glm::radians(45.f),600.0f/800.0f,0.1f,1000.0f));		//SDL GET WINDOW HEIGHT/	
		shader->Draw(*shape);
	}
}