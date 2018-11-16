#include <GL/glew.h>
#include <vector>
#include <memory>

#include "Resource.h"
#include "NonCopyable.h"
#include "VertexArray.h"

namespace toryengine
{
	class VertexArray;
	class Mesh :public Resource, private NonCopyable
	{
	public:
		Mesh(std::string path);
		//void AddFace(Face& face);
		GLuint GetId() { return id; }
		std::shared_ptr<VertexArray> GetShape() { return shape; }
	private:
		//std::vector<Face> faces;
		//vector of vec3s- push back when loading
		GLuint id;
		bool dirty;
		std::shared_ptr<Mesh> Create();
		std::shared_ptr<Mesh> Load(std::string path);
		std::shared_ptr<VertexArray> shape;

	};
}