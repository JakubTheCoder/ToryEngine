#include <iostream>

#include "BoxCollider.h"
#include "Transform.h"
#include "Root.h"

namespace toryengine
{
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

			if (GetObject()->GetComponent<Transform>()->GetPosition().x < bc->GetObject()->GetComponent<Transform>()->GetPosition().x + bc->GetSize().x &&
				GetObject()->GetComponent<Transform>()->GetPosition().x + GetSize().x > bc->GetObject()->GetComponent<Transform>()->GetPosition().x &&
				GetObject()->GetComponent<Transform>()->GetPosition().y < bc->GetObject()->GetComponent<Transform>()->GetPosition().y + bc->GetSize().y &&
				GetObject()->GetComponent<Transform>()->GetPosition().y + GetSize().y > bc->GetObject()->GetComponent<Transform>()->GetPosition().y &&
				GetObject()->GetComponent<Transform>()->GetPosition().z < bc->GetObject()->GetComponent<Transform>()->GetPosition().z + bc->GetSize().z &&
				GetObject()->GetComponent<Transform>()->GetPosition().z + GetSize().z > bc->GetObject()->GetComponent<Transform>()->GetPosition().z)
			{
				isColliding = true;
			}
			else
			{
				isColliding = false;
			}

		}

	}
}