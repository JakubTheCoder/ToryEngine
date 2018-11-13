#pragma once
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <memory>
#include <string>

#include "Resource.h"

namespace toryengine
{
	class Texture : public Resource
	{
	public:
		Texture(std::string _path);
		Texture();
		GLuint GetId() { return id; }
		glm::vec2 GetSize() { return size; }
		std::string GetPath() { return path; }
	private:
		GLuint id;
		bool dirty;
		glm::vec2 size;
		std::string path;
	};
}