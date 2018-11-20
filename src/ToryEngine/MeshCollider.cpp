
#include "MeshCollider.h"
#include "Mesh.h"
namespace toryengine
{
	std::shared_ptr<Mesh> MeshCollider::GetMesh()
	{
		return mesh.lock();
	}

	std::vector<std::shared_ptr<Triangle>> MeshCollider::GetShape()
	{
		 return mesh.lock()->GetFaces(); 
	}
}