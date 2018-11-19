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
	//float lastTime = SDL_GetTicks();

	/*
	float time = SDL_GetTicks();
	float diff = time -lastTime;
	environment->deltaTime = diff / 1000.0f;
	lastTime = time;
	*/
	std::cout << "Hello World" << std::endl;

	std::shared_ptr<toryengine::Root> root = toryengine::Root::Initalize();
	std::shared_ptr<toryengine::Object> object = root->AddObject();
	//std::shared_ptr<toryengine::Resources> resources = std::make_shared<toryengine::Resources>();

	std::shared_ptr<toryengine::Sound> s = std::make_shared<toryengine::Sound>("../Crush8-Bit.ogg");
	s->Play();

	std::shared_ptr<TestScreen> ts = object->AddComponent<TestScreen>("Green");

	std::shared_ptr<toryengine::MeshRenderer> mr = object->AddComponent<toryengine::MeshRenderer>();
	//std::shared_ptr<toryengine::MeshRenderer>mr2 = object->GetComponent<toryengine::MeshRenderer>();
	//std::shared_ptr<toryengine::Resources> temp = root->GetResources();
	//std::shared_ptr<toryengine::Texture>texture = std::make_shared<toryengine::Texture> ("../texture.jpg");
	//mr->SetTexture(root->GetResources()->Load<toryengine::Texture>("../texture.jpg"));//"texture.jpg"));
	mr->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../curuthers.obj"));
	mr->SetTexture(root->GetResources()->Load<toryengine::Texture>("../curuthers_diffuse.png"));
	std::vector<std::shared_ptr<toryengine::Object>> output;
	root->GetObjectsWithComponent<toryengine::MeshRenderer>(output);

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	root->Start();
	return 0;
}