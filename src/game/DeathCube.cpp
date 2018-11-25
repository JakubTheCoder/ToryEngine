#include "DeathCube.h"
#include "ToryEngine/Object.h"
#include "ToryEngine/Transform.h"
#include "ToryEngine/Root.h"
#include "ToryEngine/Camera.h"
#include "ToryEngine/Environment.h"
void DeathCube::OnUpdate()
{
	GetObject()->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.0f, GetRoot()->GetCurrentCamera()->GetComponent<toryengine::Camera>()->GetCameraSpeed(), 0.0f));
}