#include <memory>
#include "Mesh.h"
#include "VertexArray.h"

namespace toryengine
{
	Mesh::Mesh()
	{
	}

	void Mesh::Load(std::string _path)
	{
		model = std::make_shared<VertexArray>(_path);


		//Make Vertex Array shared pointer and pass in path 
		//shape = std::make_shared<VertexArray>(path);
		//return shape;
		//return model;
	}
}