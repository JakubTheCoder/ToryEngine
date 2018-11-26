#pragma once
#include <memory>
#include <string>
#include <vector>

namespace toryengine
{
	struct SoundImpl;
	/*!
		Sound class allows engine to have soun
	*/
	class Sound
	{
	public:
		Sound();///<Default Constructor
		Sound(std::string _path);	///<Constructor with path to sound file
		void Load(std::string _path);	///<Load audio file into game engine
		void Play(float _vol, float _varMin, float _varMax);	///<Play sound with random variance
		void Play();///<Play Sound

	private:
		std::shared_ptr<SoundImpl> impl;
		//std::vector<SoundImpl> audioSources;
	};
}