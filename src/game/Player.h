#pragma once
#include "ToryEngine/Component.h"

class Player :public toryengine::Component
{
public:
	void OnUpdate();

private:
	float velocity = 1;
	bool isJumping;

};
