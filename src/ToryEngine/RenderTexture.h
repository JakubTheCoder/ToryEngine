#include "Texture.h"

namespace toryengine
{
	///<Class that makes render textures
	class RenderTexture : public Texture
	{
	public:
		RenderTexture(int width, int height);	///<Constructor to make render texture 

		GLuint GetFbId() { return fbo; }	///<Gets the fragment data of render textures
		void Clear();	///<Clears frame buffer

	private:
		GLuint fbo;
	};
}