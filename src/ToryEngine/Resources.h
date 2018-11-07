
#include <string>
#include <list>	//includes linked lists
#include <memory>
namespace toryengine
{
	class Resource;
	class Resources
	{
	public:
		template <typename T> std::shared_ptr<T> Load(std::string path)
		{
			//creates a texture inside ad returns;
			for (size_t i = 0; i < resources.size(); i++)
			{
				if (resources.at(i) == path)
				{
					return resources.at(i);
				}
				else
				{
					std::shared_ptr<T> temp = std::make_shared<T>();
					temp->path = path;

					resources.push_back(temp);
					return temp;
				}
			}

		}
		//template <typename T> std::shared_ptr<T> Create<T>()
		//{

		//}

	private:
		std::list < std::shared_ptr<Resource>> resources;
	};
}