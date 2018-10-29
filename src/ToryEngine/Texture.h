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
		Texture(std::string path);
		~Texture();
		//void SetPixel(unsigned int x, unsigned int y, glm::vec3 color);
		//void SetPixel(unsigned int x, unsigned int y, glm::vec4 color);
		GLuint GetId() { return id; }
		glm::vec2 GetSize() { return size; }

	private:
		GLuint id;
		bool dirty;
		glm::vec2 size;
		//int type;
		//std::shared_ptr<Texture> Create(unsigned int width, unsigned int height);
		//std::shared_ptr<Texture> Load(std::string path);
	};
}