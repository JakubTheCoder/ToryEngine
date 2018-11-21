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
	class RenderTexture;

	struct Sampler
	{
		GLint id;
		std::weak_ptr<Texture> texture;
	};

	class ShaderProgram : private NonCopyable
	{
	public:
		ShaderProgram(std::string _vert, std::string _frag);

		void Draw();
		void Draw(std::shared_ptr<VertexArray> _vertexArray);
		void Draw(std::shared_ptr<RenderTexture> _renderTexture);
		void Draw(std::shared_ptr<RenderTexture> _renderTexture, std::shared_ptr<VertexArray> _vertexArray);

		void SetUniform(std::string _unifrom,glm::vec4 _value);
		void SetUniform(std::string _uniform, float _value);
		void SetUniform(std::string _uniform, glm::mat4 _value);	
		void SetUniform(std::string _uniform, std::weak_ptr<Texture> _texture);

		GLuint GetId() { return id; }

		void SetViewport(glm::vec4 _viewport) { this->viewport = _viewport; }
	private:
		GLuint id;
		std::vector<Sampler> samplers;
		std::shared_ptr<VertexArray> square;
		glm::vec4 viewport;
	};
}