#include <ToryEngine/toryengine.h>

#include <iostream>
class TestScreen : public toryengine::Component
{
public:
	void OnInit(std::string color)
	{
		std::cout << "Hello from the green test screen\n";
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

	std::shared_ptr<toryengine::Root> root = toryengine::Root::Initalize();
	std::shared_ptr<toryengine::Object> object = root->AddObject();
	std::shared_ptr<toryengine::Resources> resources = std::make_shared<toryengine::Resources>();

	std::shared_ptr<toryengine::Sound> s = std::make_shared<toryengine::Sound>("../Crush8-bit.ogg");
	s->Play();

	std::shared_ptr<TestScreen> ts = object->AddComponent<TestScreen>("Green");

	std::shared_ptr<toryengine::MeshRenderer> mr = object->AddComponent<toryengine::MeshRenderer>();
	std::shared_ptr<toryengine::MeshRenderer>mr2 = object->GetComponent<toryengine::MeshRenderer>();
	std::shared_ptr<toryengine::Resources> temp = root->GetResources();
	std::shared_ptr<toryengine::Texture>texture = std::make_shared<toryengine::Texture> ("../texture.jpg");
	mr2->SetTexture(root->GetResources()->Load<toryengine::Texture>(texture));//"texture.jpg"));

	//std::shared_ptr<Texture> t = getResources()->load<Texture>("")
	//How do we access GetResources? to load in texture?

	root->Start();
	return 0;
}