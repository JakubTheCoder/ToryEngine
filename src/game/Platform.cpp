#include <time.h>

#include "Platform.h"
#include "ToryEngine/Root.h"
#include "ToryEngine/MeshRenderer.h"
#include "ToryEngine/BoxCollider.h"
#include "ToryEngine/Transform.h"
#include "DeathCube.h"

#include <iostream>
void Platform::OnUpdate()
{
	if (isEnabled())
	{
		std::vector<std::shared_ptr<toryengine::Object>>deathCube;
		GetRoot()->GetObjectsWithComponent<DeathCube>(deathCube);
		for (size_t i = 0; i < deathCube.size(); i++)
		{
			if (GetObject()->GetComponent<toryengine::BoxCollider>()->isCollidingWith(deathCube.at(i)))
			{
				GetObject()->GetComponent<toryengine::Transform>()->Translate(glm::vec3(GetObject()->GetComponent<Platform>()->GetPlatformPos(), 25.0f, 0.0f));
			}
		}
	}
}
float Platform::GetPlatformPos()
{
	platformPos = rand() % 16 - 8;
	std::cout << "Platform position :" << platformPos << std::endl;
	return platformPos;
}

void Platform::OnInit()
{
	float platformPos;
}
