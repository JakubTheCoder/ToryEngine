#pragma once
#include <vector>
#include <memory>
#include "ToryEngine/Component.h"

class Platform :public toryengine::Component
{
public:
	void OnUpdate();
	void OnInit();
	float GetPlatformPos();
	void SetPlatformPos(float _pos) { platformPos = _pos; }
private:
	float platformPos;
};