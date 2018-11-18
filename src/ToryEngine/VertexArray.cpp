#include <iostream>
#include <fstream>

#include "VertexArray.h"
#include "VertexBuffer.h"

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

	VertexArray::VertexArray(std::string _path)
	{
		//Loading Model 
		dirty = false;
		glGenVertexArrays(1, &id);

		if (!id)
		{
			throw std::exception();
		}
		buffers.resize(10);
		std::ifstream file(_path.c_str());

		if (!file.is_open())
		{
			throw std::exception();
		}
		std::string line;	//Current line we are on
		std::vector<std::string> splitLine;	//Splits Lines up

		std::vector<glm::vec3> positions;	//Vertex Positions of Model
		std::vector<glm::vec2> texCoords;	//Texture Coords of Model
		std::vector<glm::vec3> normals;		//Normals of Model

		//Create Vertex Buffers and set them to NULL, so that if the model doesn't have a certain buffer it will not be made
		//Model will always have at least position buffer but will be treated like other buffers
		std::shared_ptr<VertexBuffer> positionBuffer = NULL;
		std::shared_ptr<VertexBuffer> texCoordBuffer = NULL;
		std::shared_ptr<VertexBuffer> normalBuffer = NULL;

		while (!file.eof())	//while we haven't reached end of file
		{
			std::getline(file, line);	//Get a line

			if (line.length() < 1)	continue;//If there is nothing on the line, continue

			SplitStringSpace(line, splitLine);	//Start spliting white space

			if (splitLine.size() < 1)	continue;//if split line is empty continue, nothing on line 


			if (splitLine.at(0) == "v")	//Is there a Vertex present on current line?
			{
				if (!positionBuffer)	//if we dont have a position buffer yet, create a position buffer
				{
					positionBuffer = std::shared_ptr<VertexBuffer>();
				}

				//Convertes String to double, since we are reading from a textfile, all text is strings,
				//which we need to covert to doubles to get position values of a vertex
				positions.push_back(glm::vec3(atof(splitLine.at(1).c_str()), atof(splitLine.at(2).c_str()), atof(splitLine.at(3).c_str())));
			}
			else if (splitLine.at(0) == "vt")	//Is there a Vertex Texture present on current line?
			{
				if (!texCoordBuffer)	//if theres no Texture Coord buffer, create one
				{
					texCoordBuffer = std::shared_ptr<VertexBuffer>();
				}
				texCoords.push_back(glm::vec2(atof(splitLine.at(1).c_str()), 1.0f - atof(splitLine.at(2).c_str())));
			}
			else if (splitLine.at(0) == "vn")	//Is there a Vertex Normal present on current line?
			{
				if (!normalBuffer)	//if there is no Normal buffer, create one
				{
					normalBuffer = std::shared_ptr<VertexBuffer>();
				}
				normals.push_back(glm::vec3(atof(splitLine.at(1).c_str()), atof(splitLine.at(2).c_str()), atof(splitLine.at(3).c_str())));
			}
			else if (splitLine.at(0) == "f")	//is there a face present on current line?
			{
				//Faces need more splitting due to how they are stored in a file
				std::vector<std::string>subsplit;

				SplitString(splitLine.at(1), '/', subsplit);
				//dont need to check for position since we know models will always have at least position
				//We need to get to first position (0) by -1 because it starts at 1
				positionBuffer->Add(positions.at(atoi(subsplit.at(0).c_str()) - 1));	//atoi convertes to interger
				if (texCoordBuffer)	//if theres a tex coord buffer add tex coords
				{
					texCoordBuffer->Add(texCoords.at(atoi(subsplit.at(1).c_str()) - 1));
				}
				if (normalBuffer)	//if there is a normal buffer, add normals
				{
					normalBuffer->Add(normals.at(atoi(subsplit.at(2).c_str()) - 1));
				}

				SplitString(splitLine.at(2), '/', subsplit);
				positionBuffer->Add(positions.at(atoi(subsplit.at(0).c_str()) - 1));	//atoi convertes to interger
				if (texCoordBuffer)	//if theres a tex coord buffer add tex coords
				{
					texCoordBuffer->Add(texCoords.at(atoi(subsplit.at(1).c_str()) - 1));
				}
				if (normalBuffer)	//if there is a normal buffer, add normals
				{
					normalBuffer->Add(normals.at(atoi(subsplit.at(2).c_str()) - 1));
				}

				SplitString(splitLine.at(3), '/', subsplit);
				positionBuffer->Add(positions.at(atoi(subsplit.at(0).c_str()) - 1));	//atoi convertes to interger
				if (texCoordBuffer)	//if theres a tex coord buffer add tex coords
				{
					texCoordBuffer->Add(texCoords.at(atoi(subsplit.at(1).c_str()) - 1));
				}
				if (normalBuffer)	//if there is a normal buffer, add normals
				{
					normalBuffer->Add(normals.at(atoi(subsplit.at(2).c_str()) - 1));
				}


				if (splitLine.size() < 5) continue;	//Ngons suck so they won't be added

				//Triangluate mesh -> draw triable between 3,4 and 1st vertex of a quad to triangulate mesh.
				SplitString(splitLine.at(3), '/', subsplit);
				positionBuffer->Add(positions.at(atoi(subsplit.at(0).c_str()) - 1));	//atoi convertes to interger
				if (texCoordBuffer)	//if theres a tex coord buffer add tex coords
				{
					texCoordBuffer->Add(texCoords.at(atoi(subsplit.at(1).c_str()) - 1));
				}
				if (normalBuffer)	//if there is a normal buffer, add normals
				{
					normalBuffer->Add(normals.at(atoi(subsplit.at(2).c_str()) - 1));
				}

				SplitString(splitLine.at(4), '/', subsplit);
				positionBuffer->Add(positions.at(atoi(subsplit.at(0).c_str()) - 1));	//atoi convertes to interger
				if (texCoordBuffer)	//if theres a tex coord buffer add tex coords
				{
					texCoordBuffer->Add(texCoords.at(atoi(subsplit.at(1).c_str()) - 1));
				}
				if (normalBuffer)	//if there is a normal buffer, add normals
				{
					normalBuffer->Add(normals.at(atoi(subsplit.at(2).c_str()) - 1));
				}

				SplitString(splitLine.at(1), '/', subsplit);
				positionBuffer->Add(positions.at(atoi(subsplit.at(0).c_str()) - 1));	//atoi convertes to interger
				if (texCoordBuffer)	//if theres a tex coord buffer add tex coords
				{
					texCoordBuffer->Add(texCoords.at(atoi(subsplit.at(1).c_str()) - 1));
				}
				if (normalBuffer)	//if there is a normal buffer, add normals
				{
					normalBuffer->Add(normals.at(atoi(subsplit.at(2).c_str()) - 1));
				}
			}
			//Convert these to weak ptrs
			SetBuffer("in_Position", positionBuffer);
			if (texCoordBuffer)
			{
				SetBuffer("in_texCoord", texCoordBuffer);
			}
			if (normalBuffer)
			{
				SetBuffer("in_Normal", normalBuffer);
			}
		}
	}

	void VertexArray::SetBuffer(std::string _attribute, std::weak_ptr<VertexBuffer> _buffer)
	{
		if (_attribute == "in_Position")		//What is attribute used for?
		{
			buffers.at(0) = _buffer.lock();		//why do we change into shared ptrs???????
		}
		else if (_attribute == "in_Color")
		{
			buffers.at(1) = _buffer.lock();
		}
		else if (_attribute == "in_TexCoord")
		{
			buffers.at(2) = _buffer.lock();
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

	void VertexArray::SplitString(std::string& _input, char _splitter, std::vector<std::string>& _output)
	{
		std::string current;

		_output.clear();	//cleans any output that we used for previous data

		for (size_t i = 0; i < _input.length(); i++)
		{
			if (_input.at(i) == _splitter)	//if spliter is a character, push it pack into output and reset current
			{
				_output.push_back(current);	//push back character into output
				current = "";	//reset current
			}
			else
			{
				current += _input.at(i);
			}
		}

		if (current.length() > 0)	//Push all the characters that are inside current 
		{
			_output.push_back(current);
		}
	}
	void VertexArray::SplitStringSpace(std::string& _input, std::vector<std::string>& _output)
	{
		std::string current;	
		_output.clear();	//Clear any current outputs
		
		//Break up any spaces, new lines etc.
		for (size_t i = 0; i < _input.length(); i++)
		{
			if (_input.at(i) == ' ' || _input.at(i) == '\r' || _input.at(i) == '\n' || _input.at(i) == '\t')
			{
				if (current.length() > 0)
				{
					_output.push_back(current);
					current = "";
				}
			}
			else
			{
				current += _input.at(i);
			}
		}

		if (current.length() > 0)
		{
			_output.push_back(current);
		}
	}
}