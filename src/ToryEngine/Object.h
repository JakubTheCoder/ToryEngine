#include <memory>
#include <vector>

namespace ToryEngine
{
	class Root;

	class Object
	{
	public:
		std::shared_ptr<Root> getRoot();	//Go to the root, allows to interact with other objects easier.
	
		template <typename T> std::shared_ptr<T> addComponent<T>();
		template <typename T, typename A> std::shared_ptr<T> addComponent<T>(A a);
		template <typename T, typename A, typename B> std::shared_ptr<T> addComponent<T>(A a, B b);
		template <typename T, typename A, typename B, typename C> std::shared_ptr<T> addComponent<T>(A a, B b, C c);

	private:
		void tick();
		void display();
	};
}