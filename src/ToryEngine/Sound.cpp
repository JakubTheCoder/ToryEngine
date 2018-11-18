#include <iostream>
#include <vector>

#include <AL/al.h>
#include <vorbis/vorbisfile.h>

#include "Sound.h"
#include "Exception.h"
namespace toryengine
{
	struct SoundImpl
	{
		ALuint id;

		~SoundImpl()
		{
			alDeleteBuffers(1, &id);
		}


		void LoadOgg(std::string _filename, std::vector<char>& _buffer, ALenum & _format, ALsizei& _freq)
		{
			int endian = 0;
			int bitStream = 0;
			long bytes = 0;
			char array[2048] = { 0 };
			vorbis_info *pInfo = NULL;
			OggVorbis_File oggFile = { 0 };

			//File Descriptor
			if (ov_fopen(_filename.c_str(), &oggFile) != 0)
			{
				std::cout << "Failed to open file " << _filename << " for decoding" << std::endl;
				throw toryengine::Exception("Failed to load Sound file");
				//throw std::exception();
			}

			pInfo = ov_info(&oggFile, -1);	//Extract info from file header

			//record format (for OpenAL)
			if (pInfo->channels == 1)
			{
				_format = AL_FORMAT_MONO16;
			}
			else
			{
				_format = AL_FORMAT_STEREO16;
			}

			//Sample rate (for OpenAL)
			_freq = pInfo->rate;

			//Keep reading bytes from file to populate output buffer
			while (true)
			{
				//read bytes into temp array
				bytes = ov_read(&oggFile, array, 2048, endian, 2, 1, &bitStream);

				if (bytes < 0)
				{
					ov_clear(&oggFile);
					std::cout << "Failed to decode file " << _filename << std::endl;
					throw std::exception();
				}
				else if (bytes == 0)
				{
					break;
				}

				//copy temp array into output buffer
				_buffer.insert(_buffer.end(), array, array + bytes);
			}
			//Clean up
			ov_clear(&oggFile);

		}
	};
	Sound::Sound() {}

	Sound::Sound(std::string _path)
	{
		Load(_path);
	}

	void Sound::Load(std::string _path)
	{
		impl = std::make_shared<SoundImpl>();
		ALenum format = 0;
		ALsizei freq = 0;
		std::vector<char> bufferData;

		alGenBuffers(1, &impl->id);

		impl->LoadOgg(_path.c_str(), bufferData, format, freq);
		alBufferData(impl->id, format, &bufferData[0], static_cast<ALsizei>(bufferData.size()), freq);
	}

	void Sound::Play()
	{
		ALuint sid = 0;
		alGenSources(1, &sid);
		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSource3f(sid, AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSourcei(sid, AL_BUFFER, impl->id);
		alSourcePlay(sid);
	}

	void Sound::Play(float _vol, float _varMin, float _varMax)
	{
		_varMin *= 1000.0f;
		_varMax *= 1000.0f;
		float variance = (std::rand() % ((int)_varMin + 1 - (int)_varMax) + (int)_varMin) / 1000.0f;	//randomise variance
		//
		ALuint sid = 0;
		alGenSources(1, &sid);
		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSource3f(sid, AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSourcei(sid, AL_BUFFER, impl->id);
		alSourcef(sid, AL_PITCH, variance);
		alSourcef(sid, AL_GAIN, _vol);
		alSourcePlay(sid);
	}
}