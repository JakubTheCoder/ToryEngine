#include "Texture.h"

namespace toryengine
{
	class RenderTexture : public Texture
	{
	public:
		RenderTexture(int width, int height);

		GLuint GetFbId() { return fbo; }
		void Clear();

	private:
		GLuint fbo;
	};
}