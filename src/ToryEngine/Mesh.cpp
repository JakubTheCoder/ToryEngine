#include <memory>
#include "Mesh.h"
#include "VertexArray.h"

namespace toryengine
{
	Mesh::Mesh(std::string path)
	{
		Load(path);
	}

	//std::shared_ptr<Mesh> Mesh::Load(std::string path)
	//{
		//Make Vertex Array shared pointer and pass in path 
		//shape = std::make_shared<VertexArray>(path);

		//return shape;

	//}
}