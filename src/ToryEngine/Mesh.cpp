#include <memory>
#include "Mesh.h"

namespace toryengine
{
	Mesh::Mesh()
	{
	}
	void Mesh::Load(std::string _path)
	{
		model = std::make_shared<VertexArray>(_path);
	}
}