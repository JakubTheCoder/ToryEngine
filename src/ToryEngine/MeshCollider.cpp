/*
#include "MeshCollider.h"
#include "Mesh.h"
#include "Root.h"
#include "VertexArray.h"
#include "BoxCollider.h"
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
		std::vector<std::shared_ptr<Object>>colBoxes;
		root.lock()->GetObjectsWithComponent<BoxCollider>(colBoxes);
		for (size_t i = 0; i < colBoxes.size(); i++)
		{
			std::shared_ptr < BoxCollider> boxCollider = colBoxes.at(i)->GetComponent<BoxCollider>();

			glm::vec3 boxCenter = boxCollider->GetSize();

			float bc[3] = { boxCenter.x,boxCenter.y,boxCenter.z };
			float hs[3] = { boxCenter.x / 2,boxCenter.y / 2,boxCenter.z / 2 };

			float triVerts[3][3] = { 0 };
			std::shared_ptr<Triangle> t = colBoxes.at(i)->GetComponent<Mesh>()->GetFaces().at(i);
			triVerts[0][0] = t->a.x;
			triVerts[0][1] = t->a.y;
			triVerts[0][2] = t->a.z;


			triVerts[1][0] = t->b.x;
			triVerts[1][1] = t->b.y;
			triVerts[1][2] = t->b.z;

			triVerts[2][0] = t->c.x;
			triVerts[2][1] = t->c.y;
			triVerts[2][2] = t->c.z;

			int res = triBoxOverlap(bc, hs, triVerts);

			if (res == 0)
			{
				isTriBoxColliding = false;
			}
			isTriBoxColliding = true;
		}
		//std::shared_ptr<BoxCollider> bc = GetObject()->GetComponent<BoxCollider>();
		//
		//for (size_t i = 0; i < colMesh.size(); i++)
		//{
		//	
		//	glm::vec3 boxCenter =bc->GetSize();
		//	float bc[3] = { boxCenter.x,boxCenter.y,boxCenter.z };
		//	float hs[3] = { boxCenter.x/2,boxCenter.y/2,boxCenter.z/2};

		//	float triVerts[3][3] = { 0 };
		//	std::shared_ptr<Triangle> t = colMesh.at(i)->GetComponent<Mesh>()->GetFaces().at(i);
		//	triVerts[0][0] = t->a.x;
		//	triVerts[0][1] = t->a.y;
		//	triVerts[0][2] = t->a.z;
	

		//	triVerts[1][0] = t->b.x;
		//	triVerts[1][1] = t->b.y;
		//	triVerts[1][2] = t->b.z;

		//	triVerts[2][0] = t->c.x;
		//	triVerts[2][1] = t->c.y;
		//	triVerts[2][2] = t->c.z;

		//	int res = triBoxOverlap(bc, hs, triVerts);

		//	if (res == 0)
		//	{
		//		isTriBoxColliding= false;
		//	}
		//	isTriBoxColliding =  true;
		//}


	}
}
*/