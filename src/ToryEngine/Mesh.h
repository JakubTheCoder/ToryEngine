#pragma once
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
		Mesh();
		GLuint GetId() { return id; }
		std::shared_ptr<VertexArray> GetShape(){ return model; }
		void SetFaces();
		std::vector<std::shared_ptr<Triangle>> GetFaces() { return faces; }
		//std::shared_ptr<Mesh> Create();
		void Load(std::string _path);
	private:
		GLuint id;
		bool dirty;

		std::shared_ptr<VertexArray> model;
		std::vector<std::shared_ptr<Triangle>>faces;

	};
}