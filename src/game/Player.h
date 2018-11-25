#pragma once
#include "ToryEngine/Component.h"
#include "ToryEngine/Sound.h"
class Player :public toryengine::Component
{
public:
	void OnUpdate();
	void OnInit();
private:
	float velocity = -1;
	bool isJumping;
	float jumpForce = 80.0f;
	float score;
	std::shared_ptr<toryengine::Sound> deathSound; 
	//s->Play();

};
