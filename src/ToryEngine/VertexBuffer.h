#pragma once
#include <GL/glew.h>
#include <glm\glm.hpp>
#include <vector>

namespace toryengine
{
	class VertexBuffer
	{
	public:
		VertexBuffer();	///<Default Constructor
		void Add(glm::vec2 _value);	///<Adds buffer data in the X and Y axis
		void Add(glm::vec3 _value);	///<Adds buffer data in the X, Y and Zaxis
		void Add(glm::vec4 _value);	///<<Adds buffer data in the X, Y,Z and W axis
		int GetComponents();	///<Get Component that is attached to object
		int GetDataSize() { return data.size(); }	///<Gets the value of data 
		GLuint GetId();

	private:
		GLuint id;	//GLuint = unsigned int
		int components;		
		std::vector<GLfloat> data;	//GLfloat = float that can be used on a lot of compilers	/ Vector of all positions.
		bool dirty;		//flag bool to set if a object is created?

	};
}