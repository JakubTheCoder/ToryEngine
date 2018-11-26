#include "Camera.h"
#include "Object.h"
#include "Transform.h"
#include "Keyboard.h"
#include "Root.h"
#include "Environment.h"

namespace toryengine
{
	void Camera::OnUpdate()
	{
		if (isEnabled())
		{
			GetObject()->GetComponent<Transform>()->Translate(glm::vec3(0.0f, cameraSpeed, 0.0f));
			cameraSpeed += 0.0002f;
		}
	}
}