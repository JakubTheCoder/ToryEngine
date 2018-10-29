
#include <string>
#include <list>	//includes linked lists
namespace toryengine
{
	class Resource;
	class Resources
	{
	public:
		template <typename T> std::shared_ptr<T> Load<T>(string::path)
		{
			//creates a texture inside ad returns;
		}
		template <typename T> std::shared_ptr<T> Create<T>()
		{

		}

	private:
		std::list < std::shared_ptr<Resource>> resources;
	};
}