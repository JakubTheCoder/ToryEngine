#pragma once
#include <GL/glew.h>
#include <vector>
#include <memory>

#include "Resource.h"
#include "NonCopyable.h"
#include "VertexArray.h"	//Triangle

namespace toryengine
{
	class VertexArray;
	/*
		Mesh class allows you to load a mesh for a model
	*/
	class Mesh :public Resource, private NonCopyable
	{
	public:
		GLuint GetId() { return id; }	///<Gets the ID of the mesh
		std::shared_ptr<VertexArray> GetShape(){ return model; }	///<Gets the model of the mesh
		void SetFaces();	///<Set the faces of a model for later use
		std::vector<std::shared_ptr<Triangle>> GetFaces() { return faces; }	///<Gets all the faces of a model
		void Load(std::string _path);	///<Loads in a model using Resources system
		glm::vec3 GetMinBoundMesh() { return model->GetMinBound(); }	///<Gets the Minimum Bound of the collider box;
		glm::vec3 GetMaxBoundMesh() { return model->GetMaxBound(); }	///<Gets the Maximum Bound of the collider box
	private:
		GLuint id;
		bool dirty;

		std::shared_ptr<VertexArray> model;
		std::vector<std::shared_ptr<Triangle>>faces;

	};
}