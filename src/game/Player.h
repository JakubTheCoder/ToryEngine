#pragma once
#include "ToryEngine/Component.h"

class Player :public toryengine::Component
{
public:
	void OnUpdate();

private:
	float velocity = -1;
	bool isJumping;
	float jumpForce = 30.0f;

};
