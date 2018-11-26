#include <glm/ext.hpp>
#include <vector>

#include "Component.h"

namespace toryengine
{
	class Transform;
	class Root;
	class Object;
	/*!
		Camera class 
	*/
	class Camera :public Component
	{
	public:
		glm::mat4 GetProjectionMatrix(){ return glm::perspective(glm::radians(45.0f), 800.0f/ 600.0f, 0.1f, 100.0f); }	///<Returns the perspective of the camera
			
		void OnUpdate();	///Update function for camera
		float GetCameraSpeed() { return cameraSpeed; }	///<Gets the movement speed of the camera
	private:
		float cameraSpeed;
	};
}