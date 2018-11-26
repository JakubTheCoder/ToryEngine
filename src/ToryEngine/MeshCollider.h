#pragma once
#include <memory>
#include <vector>

#include "VertexArray.h"
namespace toryengine
{
	class Root;
	class Mesh;
	class VertexArray;
	class BoxCollider;

	extern "C"
	{
		int triBoxOverlap(float boxcenter[3], float boxhalfsize[3], float triverts[3][3]);
	}
	/*!
		MeshCollider class that check collision between a box and triangles
	*/
	class MeshCollider : public Component
	{
		friend class Object;
	public:
		std::shared_ptr<Mesh> GetMesh(); ///<Get's the Model from the Mesh class
		std::vector<std::shared_ptr<Triangle>> GetShape();	///<Gets the triangles of the model from the Mesh Class

		void OnUpdate();	///<Update function for Mesh Collider
	private:
		std::weak_ptr<Root> root;
		std::weak_ptr<Mesh> mesh;	//for faces
		bool isTriBoxColliding;
	};
}