#include <GL/glew.h>
#include <vector>
#include "Resource.h"

namespace toryengine
{
	class Mesh :public Resource
	{
	public:
		Mesh();
		void AddFace(Face& face);
		GLuint GetId();
		
	private:
		//std::vector<Face> faces;
	};
}