#pragma once
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <memory>
#include <string>

#include "Resource.h"
#include "NonCopyable.h"

namespace toryengine
{
	class Texture : public Resource, private NonCopyable
	{
	public:
		Texture(std::string _path);
		Texture();
		GLuint GetId() { return id; }
		glm::vec2 GetSize() { return size; }
		std::string GetPath() { return path; }
		std::shared_ptr<Texture> Load(std::string path);
		std::shared_ptr<Texture>Create();
	private:
		GLuint id;
		bool dirty;
		glm::vec2 size;
		std::string path;
	};
}