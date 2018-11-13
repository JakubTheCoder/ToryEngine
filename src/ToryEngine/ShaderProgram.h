#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>
#include "NonCopyable.h"

namespace toryengine
{
	class VertexArray;
	class Texture;

	struct Sampler
	{
		GLint id;
		std::weak_ptr<Texture> texture;
	};

	class ShaderProgram : private NonCopyable
	{
	public:
		ShaderProgram(std::string vert, std::string frag);
		void Draw(VertexArray& vertexArray);

		void SetUniform(std::string unifrom,glm::vec4 value);
		void SetUniform(std::string uniform, float value);
		void SetUniform(std::string uniform, glm::mat4 value);	
		void SetUniform(std::string uniform, std::weak_ptr<Texture> texture);

		GLuint GetId() { return id; }

	private:
		GLuint id;
		std::vector<Sampler> samplers;
	};
}