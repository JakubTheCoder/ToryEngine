#pragma once
#include <GL/glew.h>
#include <glm\glm.hpp>
#include <vector>
#include <string>
#include <memory>

namespace toryengine
{
	class VertexBuffer;

	class VertexArray
	{
	public:
		VertexArray();
		void SetBuffer(std::string attribute, std::weak_ptr<VertexBuffer> buffer);
		int GetVertexCount();
		GLuint GetId();

	private:
		GLuint id;
		std::vector<std::shared_ptr<VertexBuffer>> buffers;
		bool dirty;

	};
}