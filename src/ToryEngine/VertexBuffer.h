#pragma once
#include <GL/glew.h>
#include <glm\glm.hpp>
#include <vector>

namespace toryengine
{
	class VertexBuffer
	{
	public:
		VertexBuffer();
		void Add(glm::vec3 value);	//adds position in the X, Y and Z axis
		void Add(glm::vec4 value);	//adds 4 position in the X, Y,Z and W axis
		int GetComponents();	
		int GetDataSize() { return data.size(); }
		GLuint GetId();

	private:
		GLuint id;	//GLuint = unsigned int
		int components;		//what exactly are componnts????? Points?
		std::vector<GLfloat> data;	//GLfloat = float that can be used on a lot of compilers	/ Vector of all positions.
		bool dirty;		//flag bool to set if a object is created?

	};
}