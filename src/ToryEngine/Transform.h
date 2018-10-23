#include <glm/glm.hpp>

#include "Component.h"

namespace toryengine
{
class Transform : public Component
{

	public:
		void Translate(glm::vec3 amount) { localPosition += amount; }
		void Rotate(glm::vec3 amount) { localRotation += amount; }
		void Scale(glm::vec3 amount) { localScale += amount; }
		void SetLocalPosition(glm::vec3 position) { localPosition = position; }	//Send 0,0,0 to Start at centre
		void SetLocalRotation(glm::vec3 rotation) { localRotation = rotation; }	//send 0,0,0 to be rotated correctly
		void SetLocalScale(glm::vec3 scale) { localScale = scale; }	//Send 1,1,1 to be scaled correctly in every direction

		glm::mat4 GetMatrix();

	private:
		glm::vec3 localPosition;
		glm::vec3 localRotation;
		glm::vec3 localScale;
};
}