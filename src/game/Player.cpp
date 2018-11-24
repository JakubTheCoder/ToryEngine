#include "Player.h"
#include "ToryEngine/Keyboard.h"
#include "ToryEngine/Transform.h"
#include "ToryEngine/Component.h"
#include "ToryEngine/Object.h"
void Player::OnUpdate()
{
	if (toryengine::Keyboard::IsKeyDown(SDLK_w))
	{
		GetObject()->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.0f, 0.1f, 0.0f));
		
	}
	if (toryengine::Keyboard::IsKeyDown(SDLK_s))
	{
		GetObject()->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.0f, -0.1f, 0.0f));
	}
	if (toryengine::Keyboard::IsKeyDown(SDLK_d))
	{
		GetObject()->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.1f, 0.0f, 0.0f));
	}
	if (toryengine::Keyboard::IsKeyDown(SDLK_a))
	{
		GetObject()->GetComponent<toryengine::Transform>()->Translate(glm::vec3(-0.1f, 0.0f, 0.0f));
	}
}
