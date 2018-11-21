#include <glm/ext.hpp>
#include <vector>

#include "Component.h"
namespace toryengine
{
	class Transform;
	class Root;
	class Object;

	class Camera :public Component
	{
	public:
		//void SetCurrentCamera(std::shared_ptr<Camera> _camera) { currentCamera = _camera; };
		//std::shared_ptr<Camera> GetCurrentCamera() { return currentCamera; }

		//void AddCamera(std::shared_ptr<Camera> _camera) { cameras.push_back(_camera); }

		glm::mat4 GetProjectionMatrix(){ return glm::perspective(glm::radians(45.0f), 800.0f/ 600.0f, 0.1f, 100.0f); }
			
		
	private:
		//std::vector <std::shared_ptr<Camera>> cameras;
		//std::shared_ptr<Camera> currentCamera;
	};
}