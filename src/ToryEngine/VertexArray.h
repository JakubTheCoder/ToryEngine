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
		VertexArray(std::string path);
		void SetBuffer(std::string attribute, std::weak_ptr<VertexBuffer> buffer);
		int GetVertexCount();
		GLuint GetId();

		void SplitString(std::string& input, char splitter, std::vector<std::string>&output);
		void SplitStringSpace(std::string& input, std::vector<std::string>&output);

	private:
		GLuint id;
		std::vector<std::shared_ptr<VertexBuffer>> buffers;
		bool dirty;

	};
}