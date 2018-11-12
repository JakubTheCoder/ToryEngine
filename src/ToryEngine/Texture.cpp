#include "Texture.h"
#include "stb_image/stb_image.h"

namespace toryengine
{
	Texture::Texture()
	{

	}
	Texture::Texture(std::string path)
	{
		int w = 0;	//Width of texture
		int h = 0;	//Height of texture
		int channels = 0;	//number of color channles

		unsigned char *data = stbi_load(path.c_str(), &w, &h, &channels, 4);	//Load texture using stbi library with path to texture.

		if (!data)
		{
			throw std::exception();
		}

		//set size of texture to the w and h
		size.x = w;	
		size.y = h;

		glGenTextures(1, &id);	//generate texture 1 

		if (!id)
		{
			throw std::exception();
		}

		glBindTexture(GL_TEXTURE_2D, id);	//Bind texture

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);	//Generates texture on the currently bound textre,
		//mip map level (0), 
		//how we want to store the texutre (our texture only has RGB values so thats how we store it)
		//width, height of texture
		//0 (legacy code)
		//Format and data type of the loaded image ( we pass RGB values which we then store as chars
		//Actual data we generated when loading in texture

		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(data);	//free the image data since we already have a bound image

	}

	
}