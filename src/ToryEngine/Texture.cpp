#include "Texture.h"

namespace toryengine
{
	void Texture::SetPixel(unsigned int x, unsigned int y, glm::vec3 color) {}
	void Texture::SetPixel(unsigned int x, unsigned int y, glm::vec4 color) {}
	GLuint Texture::GetId() {}

	std::shared_ptr<Texture> Texture::Create(unsigned int width, unsigned int height)
	{
		int w;
		int h;
		int channels;
		unsigned char * data = stbi_load(path.c_str(), &w, &h, &channels, 4);
	}
}