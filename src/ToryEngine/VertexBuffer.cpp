#include "VertexBuffer.h"

//What are components?
//Dirty bool (flag bool to?)
namespace toryengine
{
	VertexBuffer::VertexBuffer()	
	{
		components = 0;
		dirty = false;

		glGenBuffers(1, &id);	//Creates new VBO on GPU

		if (!id)
		{
			throw std::exception();
		}
	}

	void VertexBuffer::Add(glm::vec3 value)
	{
		if (!components)
		{
			components = 3;
		}
		if (components != 3)
		{
			throw std::exception();
		}
		//push back position of point
		data.push_back(value.x);
		data.push_back(value.y);
		data.push_back(value.z);
		dirty = true;
	}

	void VertexBuffer::Add(glm::vec4 value)
	{
		if (!components)
		{
			components = 4;
		}

		if (components != 4)
		{
			throw std::exception();
		}

		data.push_back(value.x);
		data.push_back(value.y);
		data.push_back(value.z);
		data.push_back(value.w);
		dirty = true;
	}

	int VertexBuffer::GetComponents()
	{
		if (!components)
		{
			throw std::exception();
		}
		return components;
	}

	GLuint VertexBuffer::GetId()
	{
		if (dirty)
		{
			glBindBuffer(GL_ARRAY_BUFFER, id);	//Binds making this Buffer object active
			glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*data.size(), &data.at(0), GL_STATIC_DRAW);	//Uploads copy from memory to into new VBO ???? Why do we have to do this?
			glBindBuffer(GL_ARRAY_BUFFER, 0);	//reset
			dirty = false;
		}

		return id;
	}
}