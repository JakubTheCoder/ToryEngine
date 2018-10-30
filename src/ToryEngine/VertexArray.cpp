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
		buffers.resize(10);	//Make buffer have 10 channels?
	}

	VertexArray::VertexArray(std::string path)
	{
		dirty = false;

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
		else if (attribute == "in_TexCoord")
		{
			buffers.at(2) = buffer.lock();
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

		return buffers.at(0)->GetDataSize() / buffers.at(0)->GetComponents();	// why do we do this calc?
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

	void VertexArray::SplitString(std::string& input, char splitter, std::vector<std::string>&output)
	{
		std::string current;

		output.clear();	//cleans any output that we used for previous data

		for (size_t i = 0; i < input.length(); i++)
		{
			if (input.at(i) == splitter)	//if spliter is a character, push it pack into output and reset current
			{
				output.push_back(current);
				current = "";
			}
			else
			{
				current += input.at(i);
			}
		}

		if (current.length() > 0)
		{
			output.push_back(current);
		}
	}
	void VertexArray::SplitStringSpace(std::string&input, std::vector<std::string>&output)
	{
		std::string current;
		output.clear();

		for (size_t i = 0; i < input.length(); i++)
		{
			if (input.at(i) == ' ' || input.at(i) == '\r' || input.at(i) == '\n' || input.at(i) == '\t')
			{
				if (current.length() > 0)
				{
					output.push_back(current);
					current = "";
				}
			}
			else
			{
				current += input.at(i);
			}
		}
	}
}