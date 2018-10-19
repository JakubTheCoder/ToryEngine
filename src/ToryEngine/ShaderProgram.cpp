#include <iostream>
#include <fstream>
#include <glm/ext.hpp>

#include "ShaderProgram.h"
#include "VertexArray.h"

namespace toryengine
{
	ShaderProgram::ShaderProgram(std::string vert, std::string frag)
	{
		std::ifstream file(vert.c_str());
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
		file.open(frag.c_str());
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
		{
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

			glBindAttribLocation(id, 0, "in_position");	//Binds and Make sure VAO attribute is set to first position
			glBindAttribLocation(id, 1, "in_color");	// Binds VBO

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

		}
	}
	
		void ShaderProgram::Draw(VertexArray& vertexArray)
		{
			glUseProgram(id);
			glBindVertexArray(vertexArray.GetId());

			glDrawArrays(GL_TRIANGLES, 0, vertexArray.GetVertexCount());

			glBindVertexArray(0);
			glUseProgram(0);
		}

		void ShaderProgram::SetUniform(std::string uniform, glm::vec4 value)
		{
			GLint uniformId = glGetUniformLocation(id, uniform.c_str());

			if (uniformId == -1)
			{
				throw std::exception();
			}
			glUseProgram(id);
			glUniform4f(uniformId, value.x, value.y, value.z, value.w);
			glUseProgram(0);
		}

		void ShaderProgram::SetUniform(std::string uniform, float value)
		{
			GLint uniformId = glGetUniformLocation(id, uniform.c_str());

			if (uniformId == -1)
			{
				throw std::exception();
			}
			glUseProgram(id);
			glUniform1f(uniformId, value);
			glUseProgram(0);
		}

		void ShaderProgram::SetUniform(std::string uniform, glm::mat4 value)
		{
			GLint uniformId = glGetUniformLocation(id, uniform.c_str());

			if (uniformId == -1)
			{
				throw std::exception();
			}

			glUseProgram(id);
			glUniformMatrix4fv(uniformId, 1, GL_FALSE, glm::value_ptr(value));
			glUseProgram(0);
		}
	
}