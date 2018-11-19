#pragma once
#include <GL/glew.h>
#include <glm\glm.hpp>
#include <vector>
#include <string>
#include <memory>

namespace toryengine
{
	struct Triangle
	{
		glm::vec3 a;
		glm::vec3 b;
		glm::vec3 c;
	};

	class VertexBuffer;
	//class Mesh;
	class VertexArray
	{
	public:
		VertexArray();
		VertexArray(std::string _path);
		void SetBuffer(std::string _attribute, std::weak_ptr<VertexBuffer> _buffer);
		int GetVertexCount();
		GLuint GetId();

		void SplitString(std::string& _input, char _splitter, std::vector<std::string>&_output);
		void SplitStringSpace(std::string& _input, std::vector<std::string>&_output);
		std::vector<std::shared_ptr<Triangle>> GetFaces() { return faces; }

	private:
		GLuint id;
		bool dirty;

		std::vector<std::shared_ptr<VertexBuffer>> buffers;
		std::vector < std::shared_ptr<Triangle>>faces;
	};
}