#pragma once
#include <glm/glm.hpp>

#include "Component.h"

namespace toryengine
{
	/*!
		Transform class that allows you to transform, rotate or scale any object
	*/
class Transform : public Component
{

	public:
		void Translate(glm::vec3 _amount) { localPosition += _amount; }
		void Rotate(glm::vec3 _amount) { localRotation += _amount; }
		void Scale(glm::vec3 _amount) { localScale += _amount; }
		void SetLocalPosition(glm::vec3 _position) { localPosition = _position; }	//Send 0,0,0 to Start at centre
		void SetLocalRotation(glm::vec3 _rotation) { localRotation = _rotation; }	//send 0,0,0 to be rotated correctly
		void SetLocalScale(glm::vec3 _scale) { localScale = _scale; }	//Send 1,1,1 to be scaled correctly in every direction
		glm::vec3 GetPosition() { return localPosition; }	///<Gets Position of Object
		glm::vec3 GetRotation() { return localRotation; }	///<Gets Rotation of Object
		glm::vec3 GetScale() { return localScale; }	///<Gets Scale of Object

		glm::mat4 GetMatrix();	///<Get the model matrix for drawing a feiwnd

	private:
		glm::vec3 localPosition;
		glm::vec3 localRotation;
		glm::vec3 localScale = glm::vec3(1.0f,1.0f,1.0f);
};
}