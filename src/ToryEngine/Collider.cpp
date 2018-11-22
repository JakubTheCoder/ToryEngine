
#include "Collider.h"
#include "BoxCollider.h"
//#include "MeshCollider.h"
#include "VertexArray.h"	//for Triangle
#include "Root.h"

namespace toryengine
{
	void Collider::OnUpdate()
	{
		//std::vector<std::shared_ptr<toryengine::Object>>meshOutput;
		//root.lock()->GetObjectsWithComponent<MeshCollider>(meshOutput);
	}

	//bool Collider::TriBoxCollision(glm::vec3 boxCentre, glm::vec3 boxHalfSize, Triangle t)//Faces from model
	//{
	//	float bc[3] = { boxCentre.x,boxCentre.y,boxCentre.z };
	//	float hs[3] = { boxHalfSize.x,boxHalfSize.y,boxHalfSize.z };
	//	float triVerts[3][3] = { 0 };

	//	triVerts[0][0] = t.a.x;
	//	triVerts[0][1] = t.a.y;
	//	triVerts[0][2] = t.a.z;

	//	triVerts[1][0] = t.b.x;
	//	triVerts[1][1] = t.b.y;
	//	triVerts[1][2] = t.b.z;

	//	triVerts[2][0] = t.c.x;
	//	triVerts[2][1] = t.c.y;
	//	triVerts[2][2] = t.c.z;

	//	int res = triBoxOverlap(bc, hs, triVerts);

	//	if (res == 0)
	//	{
	//		return false;
	//	}
	//	return true;
	//}

}
