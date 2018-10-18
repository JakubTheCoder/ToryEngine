#include "VertexArray.h"
#include "VertexBuffer.h"
//Attribute?
//Why do we lock buffers?
//Get VertexCount math?

namespace toryengine
{
	VertexArray::VertexArray()
	{
		dirty = false;

		glGenVertexArrays(1, &id);	// Create new VAO on the GPU

		if (!id)
		{
			throw std::exception();
		}
		buffers.resize(10);	//resize buffers vector ?????? but why?
	}

	void VertexArray::SetBuffer(std::string attribute, std::weak_ptr<VertexBuffer> buffer)
	{
		if (attribute == "in_Position")		//What is attribute used for?
		{
			buffers.at(0) = buffer.lock();		//why do we change into shared ptrs???????
		}
		else if (attribute == "in_Color")
		{
			buffers.at(1) = buffer.lock();
		}
		else
		{
			throw ::std::exception();
		}
		dirty = true;
	}

	int VertexArray::GetVertexCount()
	{
		if (!buffers.at(0))
		{
			throw std::exception();
		}

		return buffers.at(0)->GetPositionSize() / buffers.at(0)->GetComponents();	// why do we do this calc?
	}

	GLuint VertexArray::GetId()
	{
		if (dirty)
		{
			glBindVertexArray(id);	//Bind this Vertex Array Object (sets active)


			for (size_t i = 0; i < buffers.size(); i++)
			{
				if (buffers.at(i))
				{
					//binds VBOs to current position on the bound VAO.
					glBindBuffer(GL_ARRAY_BUFFER, buffers.at(i)->GetId());
					glVertexAttribPointer(i, buffers.at(i)->GetComponents(), GL_FLOAT, GL_FALSE, buffers.at(i)->GetComponents() * sizeof(GLfloat), (void *)0);

					glEnableVertexAttribArray(i);	//enable VAO
				}
				else
				{
					glDisableVertexAttribArray(i);	//else disable VAO
				}
			}

			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);
			dirty = false;
		}
		return id;
	}


}