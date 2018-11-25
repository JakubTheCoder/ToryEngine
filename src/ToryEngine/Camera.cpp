#include "Camera.h"
#include "Object.h"
#include "Transform.h"
namespace toryengine
{
	void Camera::OnUpdate()
	{
		GetObject()->GetComponent<Transform>()->Translate(glm::vec3(0.0f, cameraSpeed, 0.0f));
		cameraSpeed += 0.01f;
	}

}