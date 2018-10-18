#pragma once
#include <GL/glew.h>
#include <glm\glm.hpp>
#include <vector>
#include <string>

namespace toryengine
{
	class VertexArray
	{
	public:
		VertexArray();
		void SetBuffer(std::string attribute, VertexBuffer* buffer);
		int GetVertexCount();
		GLuint GetID();

	private:
		GLuint id;
		std::vector<VertexBuffer*> buffers;
		bool dirty;

	};
}