#include "Player.h"
#include "ToryEngine/Keyboard.h"
#include "ToryEngine/Transform.h"
#include "ToryEngine/Object.h"
#include "ToryEngine/BoxCollider.h"

#include "glm/glm.hpp"

#include <iostream>

void Player::OnUpdate()
{


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
		GetObject()->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.0f, 0.5f, 0.0f));
	}

	if (GetObject()->GetComponent<toryengine::BoxCollider>()->isBoxColliding())
	{
		std::cout << "Collision";
	}
	GetObject()->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.0f, -0.06f, 0.0f));
}
