#pragma once
#include <string>
#include <memory>
namespace toryengine
{
	class Root;
	/*!
		Resource base class that manages the loading of a Resource (e.g. Mesh, Texture)
	*/
	class Resource
	{
		friend class Resources;
	public:
		virtual ~Resource() {}
		std::string GetPath() { return path; }	///<Gets file path 
		void SetPath(std::string _path) { path = _path; }	///<Sets object's file path

		std::shared_ptr<Root> GetRoot() { return root.lock(); }	///<Has access to root 
	private:
		std::string path;
		std::weak_ptr<Root>root;
	};
}