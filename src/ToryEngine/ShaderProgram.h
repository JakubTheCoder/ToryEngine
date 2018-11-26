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
	/*!
		Shader Class
	*/
	class ShaderProgram : private NonCopyable
	{
	public:
		ShaderProgram(std::string _vert, std::string _frag);	///<Sets up Shader and vertex and fragment shaders

		void Draw();///<Draws texture canvas
		void Draw(std::shared_ptr<VertexArray> _vertexArray);	///<Draws Model
		void Draw(std::shared_ptr<RenderTexture> _renderTexture);	///<Draws Render Texture
		void Draw(std::shared_ptr<RenderTexture> _renderTexture, std::shared_ptr<VertexArray> _vertexArray);	//<Draws render texture and Draws models

		void SetUniform(std::string _unifrom,glm::vec4 _value);		///<Sets uniforms for shader
		void SetUniform(std::string _uniform, float _value);	///<Sets uniforms for shader
		void SetUniform(std::string _uniform, glm::mat4 _value);	///<Sets uniforms for shader
		void SetUniform(std::string _uniform, std::shared_ptr<Texture> _texture);///<Sets uniforms and texturefor shader

		GLuint GetId() { return id; }	///>Returns shader Id


		void SetViewport(glm::vec4 _viewport) { this->viewport = _viewport; }///<Sets Viewport
	private:
		GLuint id;
		std::vector<Sampler> samplers;
		std::shared_ptr<VertexArray> square;
		glm::vec4 viewport;
	};
}