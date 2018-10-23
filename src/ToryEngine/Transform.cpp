#include "Transform.h"
#include <glm/ext.hpp> //things like translate
namespace toryengine
{
	glm::mat4 Transform::GetMatrix()
	{
		glm::mat4 rtn = glm::translate(glm::mat4(1.0f), localPosition);
		rtn = glm::rotate(rtn, glm::radians(localRotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		rtn = glm::scale(rtn, localScale);
		return rtn;
		
	}

}