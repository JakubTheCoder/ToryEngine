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
		if (isEnabled())
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

	bool BoxCollider::isCollidingWith(std::shared_ptr<Object> other)
	{

		if (isEnabled())
		{
			if (GetObject()->GetComponent<Transform>()->GetPosition().x + GetMinSize().x < other->GetComponent<Transform>()->GetPosition().x + other->GetComponent<BoxCollider>()->GetMaxSize().x &&
				GetObject()->GetComponent<Transform>()->GetPosition().x + GetMaxSize().x > other->GetComponent<Transform>()->GetPosition().x + other->GetComponent<BoxCollider>()->GetMinSize().x &&
				GetObject()->GetComponent<Transform>()->GetPosition().y + GetMinSize().y < other->GetComponent<Transform>()->GetPosition().y + other->GetComponent<BoxCollider>()->GetMaxSize().y &&
				GetObject()->GetComponent<Transform>()->GetPosition().y + GetMaxSize().y > other->GetComponent<Transform>()->GetPosition().y + other->GetComponent<BoxCollider>()->GetMinSize().y &&
				GetObject()->GetComponent<Transform>()->GetPosition().z + GetMinSize().z < other->GetComponent<Transform>()->GetPosition().z + other->GetComponent<BoxCollider>()->GetMaxSize().z &&
				GetObject()->GetComponent<Transform>()->GetPosition().z + GetMaxSize().z > other->GetComponent<Transform>()->GetPosition().z + other->GetComponent<BoxCollider>()->GetMinSize().z)
			{
				return true;
			}

			return false;
		}
	}

}