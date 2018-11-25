#include "Player.h"
#include "ToryEngine/Keyboard.h"
#include "ToryEngine/Transform.h"
#include "glm/glm.hpp"
#include "ToryEngine/Object.h"
#include "ToryEngine/BoxCollider.h"
#include "ToryEngine/Root.h"
#include "Platform.h"

#include <iostream>

void Player::OnUpdate()
{
	//std::cout << "Pos" << GetObject()->GetComponent<toryengine::Transform>()->GetPosition().y;
	velocity= -1;

	std::vector<std::shared_ptr<toryengine::Object>> platforms;	//Makes a vector of objects 
	GetRoot()->GetObjectsWithComponent<Platform>(platforms);	//Gets all the objects with a BoxCollider
	for (size_t i = 0; i < platforms.size(); i++)
	{
		if (velocity <= 0)
		{
			if (GetObject()->GetComponent<toryengine::BoxCollider>()->isBoxColliding() && platforms.at(i)->GetComponent<Platform>())
			{
				//velocity *= -jumpForce;
				GetObject()->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.0f, 3.0f, 0.0f));
			}
		}
	}
	if (toryengine::Keyboard::IsKeyDown(SDLK_d))
	{
		GetObject()->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.1f, 0.0f, 0.0f));
	}
	if (toryengine::Keyboard::IsKeyDown(SDLK_a))
	{
		GetObject()->GetComponent<toryengine::Transform>()->Translate(glm::vec3(-0.1f, 0.0f, 0.0f));
	}
	if (toryengine::Keyboard::IsKeyDown(SDLK_SPACE))
	{
		GetObject()->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.0f, 5.0f, 0.0f));
	}


	GetObject()->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.0f, 0.1f*velocity, 0.0f));
}
