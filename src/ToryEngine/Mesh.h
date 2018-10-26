#include <GL/glew.h>
#include <vector>
#include <memory>
#include "Resource.h"

namespace toryengine
{
	class Mesh :public Resource
	{
	public:
		Mesh();
		//void AddFace(Face& face);
		GLuint GetId();
		
	private:
		//std::vector<Face> faces;
		bool dirty;
		std::shared_ptr<Mesh> create();
		std::shared_ptr<Mesh> load(std::string path);

	};
}