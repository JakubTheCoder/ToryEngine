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
	class VertexArray
	{
	public:
		VertexArray();	///<Default Constructor
		VertexArray(std::string _path);	///<Loads in model based on path
		void SetBuffer(std::string _attribute, std::weak_ptr<VertexBuffer> _buffer);	///<Sets Buffers
		int GetVertexCount();	///<gets amount of Vertexs
		GLuint GetId();	///<Gets Vertex  Array ID

		void SplitString(std::string& _input, char _splitter, std::vector<std::string>&_output);	///<Function used to read models from obj file 
		void SplitStringSpace(std::string& _input, std::vector<std::string>&_output);///<function used to read faces on model file
		std::vector<std::shared_ptr<Triangle>> GetFaces() { return faces; }	///<Gets all the triangles on a mesh

		glm::vec3 GetMinBound() { return minBound; }	///<Gets MinBounds of Collider box
		glm::vec3 GetMaxBound() { return maxBound; }	///<Gets MaxBounds for Collider did 
	private:
		GLuint id;
		bool dirty;

		std::vector<std::shared_ptr<VertexBuffer>> buffers;
		std::vector < std::shared_ptr<Triangle>>faces;

		glm::vec3 minBound = glm::vec3(INFINITY);
		glm::vec3 maxBound = glm::vec3(-INFINITY);

	};
}