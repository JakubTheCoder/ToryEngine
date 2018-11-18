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
		Sound(std::string _path);
		void Load(std::string _path);
		void Play(float _vol, float _varMin, float _varMax);
		void Play();

	private:
		std::shared_ptr<SoundImpl> impl;
		//std::vector<SoundImpl> audioSources;
	};
}