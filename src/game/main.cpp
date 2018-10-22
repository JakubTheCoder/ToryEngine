#include <ToryEngine/toryengine.h>

#include <iostream>
class TestScreen : public toryengine::Component
{
public:
	void OnInit(std::string color)
	{
		std::cout << "OnInit " << std::endl;
	}

	void OnBegin()
	{
	}

	void OnUpdate()
	{
	}
	void OnDraw()
	{
	}
};

int main()
{

	std::cout << "Hello World" << std::endl;

	std::shared_ptr<toryengine::Root> c = toryengine::Root::Initalize();

	std::shared_ptr<toryengine::Object> e = c->AddObject();

	std::shared_ptr<TestScreen> ts = e->AddComponent<TestScreen>("Green");

	std::shared_ptr<toryengine::MeshRenderer> mr = e->AddComponent<toryengine::MeshRenderer>();
	std::shared_ptr<toryengine::MeshRenderer>mr2 = e->GetComponent<toryengine::MeshRenderer>();

	c->Start();
	return 0;
}