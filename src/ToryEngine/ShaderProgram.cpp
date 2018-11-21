#include <iostream>
#include <fstream>
#include <glm/ext.hpp>

#include "ShaderProgram.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "Texture.h"
#include "RenderTexture.h"

namespace toryengine
{
	ShaderProgram::ShaderProgram(std::string _vert, std::string _frag)
	{
		std::ifstream file(_vert.c_str());
		std::string vertSrc;

		if (!file.is_open())
		{
			throw std::exception();
		}

		while (!file.eof())
		{
			std::string line;
			std::getline(file, line);
			vertSrc += line + "\n";
		}
		file.close();
		file.open(_frag.c_str());
		std::string fragSrc;

		if (!file.is_open())
		{
			throw std::exception();
		}

		while (!file.eof())
		{
			std::string line;
			std::getline(file, line);
			fragSrc += line + "\n";
		}

		//Prep  Vertex Shader
		const GLchar *vs = vertSrc.c_str();	//
		GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);	//Make Vertex Shader
		glShaderSource(vertexShaderId, 1, &vs, NULL);
		glCompileShader(vertexShaderId);	//Compile vert shader
		GLint success = 0;
		glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);	//checks if shader compiled

		if (!success)
		{
			throw std::exception();
		}
		//////

		//Prep FragmentShader
		const GLchar *fs = fragSrc.c_str();
		
		GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);	//Make Frag Shader
		glShaderSource(fragmentShaderId, 1, &fs, NULL);
		glCompileShader(fragmentShaderId);	//Compile frag shader
		glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);	//checks if shader compiled

		if (!success)
		{
			throw::std::exception();
		}

		//Prep Shader
		id = glCreateProgram();	//create shader program
		glAttachShader(id, vertexShaderId);	//attach vertex to shader
		glAttachShader(id, fragmentShaderId);	//attach fragment to shader

		glBindAttribLocation(id, 0, "in_Position");	//Binds and Make sure VAO attribute is set to first position
		glBindAttribLocation(id, 1, "in_Color");	// Binds VBO
		glBindAttribLocation(id, 2, "in_TexCoord");
		glBindAttribLocation(id, 3, "in_Normal");

		if (glGetError() != GL_NO_ERROR)
		{
			throw std::exception();
		}


		glLinkProgram(id);	//Link the programs together
		glGetProgramiv(id, GL_LINK_STATUS, &success);	//check for errors
		if (!success)
		{
			throw std::exception();
		}

		//Detatched linked shader programs and delete, as they are no longer needed
		glDetachShader(id, vertexShaderId);
		glDeleteShader(vertexShaderId);
		glDetachShader(id, fragmentShaderId);
		glDeleteShader(fragmentShaderId);

		//Create a simple square to use as a canvis for render texture
		std::shared_ptr<VertexBuffer> squarePos = std::make_shared<VertexBuffer>();
		std::shared_ptr<VertexBuffer> squareTex = std::make_shared<VertexBuffer>();

		//First Triangle
		squarePos->Add(glm::vec2(-1.0f, 1.0f));
		squarePos->Add(glm::vec2(-1.0f, -1.0f));
		squarePos->Add(glm::vec2(1.0f, -1.0f));
		//Second Triangle
		squarePos->Add(glm::vec2(1.0f, -1.0f));
		squarePos->Add(glm::vec2(1.0f, 1.0f));
		squarePos->Add(glm::vec2(-1.0f, 1.0f));

		//Texture Coords for Square
		//First Tri
		squareTex->Add(glm::vec2(0.0f, 0.0f));
		squareTex->Add(glm::vec2(0.0f, -1.0f));
		squareTex->Add(glm::vec2(1.0f, -1.0f));
		//Second Tri
		squareTex->Add(glm::vec2(1.0f, -1.0f));
		squareTex->Add(glm::vec2(1.0f, 0.0f));
		squareTex->Add(glm::vec2(0.0f, 0.0f));

		square = std::make_shared<VertexArray>();
		square->SetBuffer("in_Position", squarePos);
		square->SetBuffer("in_TexCoord", squareTex);
	}
	void ShaderProgram::Draw()
	{
		Draw(square);
	}
	void ShaderProgram::Draw(std::shared_ptr<VertexArray> _vertexArray)
	{
		glUseProgram(id);
		glBindVertexArray(_vertexArray->GetId());

		for (size_t i = 0; i < samplers.size(); i++)	//Go through all textures and draw them
		{
			glActiveTexture(GL_TEXTURE0 + i);
			if (samplers.at(i).texture.lock())
			{
				glBindTexture(GL_TEXTURE_2D, samplers.at(i).texture.lock()->GetId());
			}
			else
			{
				glBindTexture(GL_TEXTURE_2D, 0);
			}
		}
		glDrawArrays(GL_TRIANGLES, 0, _vertexArray->GetVertexCount());

		for (size_t i = 0; i < samplers.size(); i++)
		{
			glActiveTexture(GL_TEXTURE0 + i);
			glBindTexture(GL_TEXTURE20, 0);
		}

		glBindVertexArray(0);
		glUseProgram(0);
	}
	
	void ShaderProgram::Draw(std::shared_ptr<RenderTexture> _renderTexture)
	{
		Draw(_renderTexture, square);
	}

	void ShaderProgram::Draw(std::shared_ptr<RenderTexture> _renderTexture, std::shared_ptr<VertexArray> _vertexArray)
	{
		glBindFramebuffer(GL_FRAMEBUFFER, _renderTexture->GetFbId());
		glm::vec4 lastViewport = viewport;
		viewport = glm::vec4(0, 0, _renderTexture->GetSize().x, _renderTexture->GetSize().y);
		Draw(_vertexArray);
		viewport = lastViewport;
		glBindFramebuffer(GL_FRAMEBUFFER, 0);

	}

	void ShaderProgram::SetUniform(std::string _uniform, glm::vec4 _value)
	{
		GLint uniformId = glGetUniformLocation(id, _uniform.c_str());

		if (uniformId == -1)
		{
			throw std::exception();
		}
		glUseProgram(id);
		glUniform4f(uniformId, _value.x, _value.y, _value.z, _value.w);
		glUseProgram(0);
	}

	void ShaderProgram::SetUniform(std::string _uniform, float _value)
	{
		GLint uniformId = glGetUniformLocation(id, _uniform.c_str());

		if (uniformId == -1)
		{
			throw std::exception();
		}
		glUseProgram(id);
		glUniform1f(uniformId, _value);
		glUseProgram(0);
	}

	void ShaderProgram::SetUniform(std::string _uniform, glm::mat4 _value)
	{
		GLint uniformId = glGetUniformLocation(id, _uniform.c_str());

		if (uniformId == -1)
		{
			throw std::exception();
		}

		glUseProgram(id);
		glUniformMatrix4fv(uniformId, 1, GL_FALSE, glm::value_ptr(_value));
		glUseProgram(0);
	}

	void ShaderProgram::SetUniform(std::string _uniform, std::weak_ptr<Texture> _texture)
	{
		GLint uniformId = glGetUniformLocation(id, _uniform.c_str());

		if (uniformId == -1)
		{
			throw std::exception();
		}

		for (size_t i = 0; i < samplers.size(); i++)
		{
			if (samplers.at(i).id == uniformId)
			{
				samplers.at(i).texture = _texture;

				glUseProgram(id);
				glUniform1i(uniformId, i);
				glUseProgram(0);
				return;
			}
		}

		Sampler s;
		s.id = uniformId;
		s.texture = _texture;
		samplers.push_back(s);

		glUseProgram(id);
		glUniform1i(uniformId, samplers.size() - 1);
		glUseProgram(0);
	}

}