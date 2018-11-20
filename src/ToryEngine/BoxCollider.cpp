
#include "BoxCollider.h"
#include "Transform.h"
#include "Root.h"

namespace toryengine
{
	//std::shared_ptr<Root> BoxCollider::GetRoot()
	//{
	//	return root.lock();
	//}

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


			//X Axis Collision 
			//if (box1.x+box1.w<box2.x || box1.x > box2.x + box2.w)isColliding =  false);
			if (GetObject()->GetComponent<Transform>()->GetPosition().x + GetSize().x < bc->GetObject()->GetComponent<Transform>()->GetPosition().x
				|| GetObject()->GetComponent<Transform>()->GetPosition().x> bc->GetObject()->GetComponent<Transform>()->GetPosition().x + bc->GetSize().x)
			{
				isBoxColliding = false;
			}

			//Y Axis Collision
			//if(box1.y+box1.h<boxY2||box1.y>box2.y+box2.h)isColliding = false;
			if (GetObject()->GetComponent<Transform>()->GetPosition().y + GetSize().y < bc->GetObject()->GetComponent<Transform>()->GetPosition().y
				|| GetObject()->GetComponent<Transform>()->GetPosition().y> bc->GetObject()->GetComponent<Transform>()->GetPosition().y + bc->GetSize().y)
			{
				isBoxColliding = false;
			}

			//Z Axis Collision
			//if(box1.z+box1.d<box2.z||box1.z > box2.z+box2.h) isColliding = false;
			if (GetObject()->GetComponent<Transform>()->GetPosition().z + GetSize().z < bc->GetObject()->GetComponent<Transform>()->GetPosition().z
				|| GetObject()->GetComponent<Transform>()->GetPosition().z> bc->GetObject()->GetComponent<Transform>()->GetPosition().z + bc->GetSize().z)
			{
				isBoxColliding = false;
			}
			isBoxColliding = true;
		}

	}
}