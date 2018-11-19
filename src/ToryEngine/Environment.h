#include <SDL2/SDL_timer.h>

namespace toryengine
{
	class Environment
	{
	public:
		float GetDeltaTime() { return deltaTime; }
		void SetDeltaTime(float time) { deltaTime = time; }
	private:
		float deltaTime;
	};
}