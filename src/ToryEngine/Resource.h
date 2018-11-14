#pragma once
#include <string>
#include <memory>
namespace toryengine
{
	class Root;

	class Resource
	{
		friend class Resources;
	public:
		virtual ~Resource() {}
		std::string GetPath() { return path; }
		void SetPath(std::string _path) { path = _path; }

		std::shared_ptr<Root> GetRoot();
	private:
		std::string path;
		std::weak_ptr<Root>root;
	};
}