#pragma once
#include <string>
#include <vector>	//includes linked lists
#include <memory>

#include "Texture.h"
#include "Mesh.h"

namespace toryengine
{
	class Resource;

	class Resources
	{
	public:
		template <typename T>
		std::shared_ptr<T> Load(std::string _path)
		{
			//creates a texture inside and returns;
			std::shared_ptr<T> temp = std::make_shared<T>();

			for (size_t i = 0; i < resources.size(); i++)
			{
				if (resources.at(i)->GetPath() == _path)
				{
					return std::dynamic_pointer_cast <T>(resources.at(i));
				}

			}
			temp->Load(_path);
			temp->SetPath(_path);
			temp->GetRoot();

			resources.push_back(temp);
			return temp;

			//return std::shared_ptr<T>();

		}
		//Creates a resource
		//template <typename T> std::shared_ptr<T> Create<T>()
		//{

		//}

	private:
		std::vector< std::shared_ptr<Resource>> resources;
	};
}