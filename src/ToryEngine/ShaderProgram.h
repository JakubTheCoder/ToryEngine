#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>
#include <memory>
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
		ShaderProgram(std::string _vert, std::string _frag);
		void Draw(VertexArray& _vertexArray);

		void SetUniform(std::string _unifrom,glm::vec4 _value);
		void SetUniform(std::string _uniform, float _value);
		void SetUniform(std::string _uniform, glm::mat4 _value);	
		void SetUniform(std::string _uniform, std::weak_ptr<Texture> _texture);

		GLuint GetId() { return id; }

	private:
		GLuint id;
		std::vector<Sampler> samplers;
	};
}