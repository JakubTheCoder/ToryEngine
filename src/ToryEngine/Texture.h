#include <glm/glm.hpp>
#include <GL/glew.h>
#include <memory>
#include <string>

#include "Resource.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace toryengine
{
	class Texture : public Resource
	{
	public:
		~Texture();
		void SetPixel(unsigned int x, unsigned int y, glm::vec3 color);
		void SetPixel(unsigned int x, unsigned int y, glm::vec4 color);
		GLuint GetId();

	private:
		GLuint id;
		bool dirty;
		int type;
		std::shared_ptr<Texture> Create(unsigned int width, unsigned int height);
		std::shared_ptr<Texture> Load(std::string path);
	};
}