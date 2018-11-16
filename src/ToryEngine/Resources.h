
#include <string>
#include <vector>	//includes linked lists
#include <memory>

#include "Texture.h"
namespace toryengine
{
	class Resource;
	class Resources
	{
	public:
		template <typename T> std::shared_ptr<T> Load(std::shared_ptr<T> res)//std::string path)
		{
			//creates a texture inside and returns;
			std::shared_ptr<T> temp = std::make_shared<T>();

			for (size_t i = 0; i < resources.size(); i++)
			{
				if (resources.at(i)->GetPath() == res->GetPath())
				{
					return std::dynamic_pointer_cast <T>(resources.at(i));
				}

			}
			//temp->Load(path);
			temp->SetPath(res->GetPath());
			temp->GetRoot();

			resources.push_back(temp);
			return temp;

			//return std::shared_ptr<T>();

		}
		//Creates a texture
		//template <typename T> std::shared_ptr<T> Create<T>()
		//{

		//}

	private:
		std::vector< std::shared_ptr<Resource>> resources;
	};
}