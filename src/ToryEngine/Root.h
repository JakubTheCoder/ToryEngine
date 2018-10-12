#include <memory>
#include <vector>

#include <SDL2/SDL.h>
namespace ToryEngine	//Makes sure it uses the Tory Engine functions, even if user has same function names.
{
	class Object;

	class Root
	{
	public:
		void start();
		void stop();

		std::shared_ptr<Object> addObject();	//Adds a object to the vector

	private:
		//ENVIRNOMENT?
		//std::shared_ptr<Environment>;

		//Entities
		//std::vector<std::shared_ptr<Entity>>;	//vector containing all entities.

		bool running;

	};