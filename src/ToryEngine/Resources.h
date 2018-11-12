
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
		template <typename T> std::shared_ptr<T> Load(std::string path)
		{
			//creates a texture inside and returns;
			std::shared_ptr<T> temp = std::make_shared<T>();
			if (resources.size() !=0)
			{
				for (size_t i = 0; i < resources.size(); i++)
				{
					if (resources.at(i)->GetPath() == path)
					{
						return std::dynamic_pointer_cast <T>(resources.at(i));
						//temp = resources.at(i);
						//return temp;
					}

				}
			}
			else
			{
				temp->SetPath(path);
				temp->GetRoot();

				resources.push_back(temp);
				return temp;
			}

				

		}
		//Creates a texture
		//template <typename T> std::shared_ptr<T> Create<T>()
		//{

		//}

	private:
		std::vector< std::shared_ptr<Resource>> resources;
	};
}