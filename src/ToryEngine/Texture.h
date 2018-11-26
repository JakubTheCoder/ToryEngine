#pragma once
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <memory>
#include <string>

#include "Resource.h"
#include "NonCopyable.h"

namespace toryengine
{
	/*!
		Texture class that allows you to load textures onto models
	*/
	class Texture : public Resource, private NonCopyable
	{
		friend class RenderTexture;

	public:
		Texture() {}///<Default constructor
		Texture(int width, int height);	///<Binds Texutre
		GLuint GetId() { return id; }	///<Returns texutre ID
		glm::vec2 GetSize() { return size; }	///<Returns the size of the texture

		std::string GetPath() { return path; }	///<Gets path to the texture file

		void Load(std::string _path);	///<Loads in Texture from file
	private:
		GLuint id;
		bool dirty;
		glm::vec2 size;
		std::string path;
	};
}