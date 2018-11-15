#pragma once
#include <memory>
#include <string>
#include <vector>
namespace toryengine
{
	struct SoundImpl;

	class Sound
	{
	public:
		Sound();
		Sound(std::string path);
		void Load(std::string path);
		void Play(float vol, float varMin, float varMax);
		void Play();

	private:
		std::shared_ptr<SoundImpl> impl;
		//std::vector<SoundImpl> audioSources;
	};
}