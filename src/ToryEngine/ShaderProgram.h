#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>
//Set uniform with mat 4?
namespace toryengine
{
	class VertexArray;

	class ShaderProgram
	{
	public:
		ShaderProgram(std::string vert, std::string frag);
		void Draw(VertexArray& vertexArray);

		void SetUniform(std::string unifrom,glm::vec4 value);
		void SetUniform(std::string uniform, float value);

		void SetUniform(std::string uniform, glm::mat4 value);	
		GLuint GetId() { return id; }

	private:
		GLuint id;
	};
}