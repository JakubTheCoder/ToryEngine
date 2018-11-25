#include <glm/glm.hpp>
#include "Player.h"

#include "ToryEngine/Keyboard.h"
#include "ToryEngine/Transform.h"
#include "ToryEngine/Object.h"
#include "ToryEngine/BoxCollider.h"
#include "ToryEngine/Root.h"
#include "ToryEngine/Environment.h"
#include "Platform.h"
#include "DeathCube.h"

#include <iostream>

void Player::OnUpdate()
{
	score++;
	//std::cout << "Pos" << GetObject()->GetComponent<toryengine::Transform>()->GetPosition().y;
	velocity= -1;

	std::vector<std::shared_ptr<toryengine::Object>> platforms;	//Makes a vector of objects 
	GetRoot()->GetObjectsWithComponent<Platform>(platforms);	//Gets all the objects with a BoxCollider

	std::vector<std::shared_ptr<toryengine::Object>>deathCube;
	GetRoot()->GetObjectsWithComponent<DeathCube>(deathCube);
	for (size_t i = 0; i < deathCube.size(); i++)
	{
		if (GetObject()->GetComponent<toryengine::BoxCollider>()->isCollidingWith(deathCube.at(i)))
		{
			//Delete character
			//Display Lose Screen
			std::cout << "Death";
		}
	}
	//GetObject()->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.0f, (0.1f*velocity)*-jumpForce, 0.0f));
	for (size_t i = 0; i < platforms.size(); i++)
	{

		if (velocity <= 0)
		{
			if (GetObject()->GetComponent<toryengine::BoxCollider>()->isCollidingWith(platforms.at(i)))
			{
				GetObject()->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.0f, ((0.1f*velocity)*-jumpForce), 0.0f));
				//std::cout << "Jump";
			}
		}
		else
		{
			continue;
		}
	}
	if (toryengine::Keyboard::IsKeyDown(SDLK_d))
	{
		GetObject()->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.5f, 0.0f, 0.0f));
	}
	if (toryengine::Keyboard::IsKeyDown(SDLK_a))
	{
		GetObject()->GetComponent<toryengine::Transform>()->Translate(glm::vec3(-0.5f, 0.0f, 0.0f));
	}

	GetObject()->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.0f, 0.1f*velocity, 0.0f));
}
