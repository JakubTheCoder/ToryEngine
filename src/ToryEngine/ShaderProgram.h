#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>

namespace toryengine
{
	class VertexArray;

	class ShaderProgram
	{
	public:
		ShaderProgram(std::string vert, std::string frag);
		void Draw(VertexArray& vertexArray);
		void SetUniform(glm::vec4 uniform);
		void SetUniform(float uniform);
		GLuint GetId();

	private:
		Gluint id;
	};
}