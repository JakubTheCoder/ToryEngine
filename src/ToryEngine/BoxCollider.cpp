#include <iostream>

#include "BoxCollider.h"
#include "Transform.h"
#include "Root.h"
#include "MeshRenderer.h"
#include "Mesh.h"
namespace toryengine
{
	void BoxCollider::OnInit()
	{
		SetSize();
	}
	void BoxCollider::SetSize()
	{

		sizeMin = GetObject()->GetComponent<MeshRenderer>()->GetMesh()->GetMinBoundMesh();
		sizeMax = GetObject()->GetComponent<MeshRenderer>()->GetMesh()->GetMaxBoundMesh();

	}
	//void BoxCollider::SetSize(glm::vec3 p1, glm::vec3 p2)
	//{
	//	sizeMin = p1;
	//	sizeMax = p2;
	//}

	glm::vec3 BoxCollider::GetSize() 
	{
		return glm::vec3(sizeMax.x - sizeMin.x, sizeMax.y - sizeMin.y, sizeMax.z - sizeMin.z); 
	}
	glm::vec3 BoxCollider::GetMinSize()
	{
		return sizeMin;
	}
	glm::vec3 BoxCollider::GetMaxSize()
	{
		return sizeMax;
	}

	void BoxCollider::OnUpdate()
	{
		std::vector<std::shared_ptr<Object>> colBoxes;	//Makes a vector of objects 
		root.lock()->GetObjectsWithComponent<BoxCollider>(colBoxes);	//Gets all the objects with a BoxCollider
		for (size_t i = 0; i < colBoxes.size(); i++)
		{
			std::shared_ptr<BoxCollider> bc = colBoxes.at(i)->GetComponent<BoxCollider>();
			if (bc.get() == this)
			{
				continue;
			}
			if (GetObject()->GetComponent<Transform>()->GetPosition().x + GetMinSize().x < bc->GetObject()->GetComponent<Transform>()->GetPosition().x + bc->GetMaxSize().x &&
				GetObject()->GetComponent<Transform>()->GetPosition().x + GetMaxSize().x > bc->GetObject()->GetComponent<Transform>()->GetPosition().x + bc->GetMinSize().x &&
				GetObject()->GetComponent<Transform>()->GetPosition().y + GetMinSize().y < bc->GetObject()->GetComponent<Transform>()->GetPosition().y + bc->GetMaxSize().y &&
				GetObject()->GetComponent<Transform>()->GetPosition().y + GetMaxSize().y > bc->GetObject()->GetComponent<Transform>()->GetPosition().y + bc->GetMinSize().y &&
				GetObject()->GetComponent<Transform>()->GetPosition().z + GetMinSize().z < bc->GetObject()->GetComponent<Transform>()->GetPosition().z + bc->GetMaxSize().z &&
				GetObject()->GetComponent<Transform>()->GetPosition().z + GetMaxSize().z > bc->GetObject()->GetComponent<Transform>()->GetPosition().z + bc->GetMinSize().z)
			{
				isColliding = true;
				return;
			}
		}
		isColliding = false;

	}
}