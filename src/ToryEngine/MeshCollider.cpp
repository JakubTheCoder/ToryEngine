
#include "MeshCollider.h"
#include "Mesh.h"
#include "Root.h"

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

	void MeshCollider::OnUpdate()
	{
		std::vector<std::shared_ptr<toryengine::Object>>meshOutput;
		root.lock()->GetObjectsWithComponent<MeshCollider>(meshOutput);


	}
}