#include <glm/glm.hpp>

#include "Component.h"

namespace toryengine
{
class Transform : public Component
{

	public:
		void Translate(glm::vec3 _amount) { localPosition += _amount; }
		void Rotate(glm::vec3 _amount) { localRotation += _amount; }
		void Scale(glm::vec3 _amount) { localScale += _amount; }
		void SetLocalPosition(glm::vec3 _position) { localPosition = _position; }	//Send 0,0,0 to Start at centre
		void SetLocalRotation(glm::vec3 _rotation) { localRotation = _rotation; }	//send 0,0,0 to be rotated correctly
		void SetLocalScale(glm::vec3 _scale) { localScale = _scale; }	//Send 1,1,1 to be scaled correctly in every direction

		glm::mat4 GetMatrix();

	private:
		glm::vec3 localPosition;
		glm::vec3 localRotation;
		glm::vec3 localScale = glm::vec3(1.0f,1.0f,1.0f);
};
}