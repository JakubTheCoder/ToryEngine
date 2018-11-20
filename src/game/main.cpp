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

class MoveCube :public toryengine::Component
{
public :

	void OnUpdate()
	{

		GetObject()->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.05f * move_dir, 0.0f, 0.0f));
		if (GetObject()->GetComponent<toryengine::Transform>()->GetPosition().x > 4.0f
			|| GetObject()->GetComponent<toryengine::Transform>()->GetPosition().x < -4.0f)
		{
			move_dir *= -1;
		}
		if (GetObject()->GetComponent<toryengine::BoxCollider>()->isBoxColliding())
		{
			move_dir *= -1;
		}
		//if (glm::distance(lastPos, GetObject()->GetComponent<toryengine::Transform>()->GetPosition())>1.0f)
		//{
		//	GetObject()->GetComponent<toryengine::Transform>()->SetLocalPosition(lastPos);
		//}
		//lastPos = GetObject()->GetComponent<toryengine::Transform>()->GetPosition();
	}
private:
	float move_dir = 1;
	glm::vec3 lastPos;
};

class MoveCube2 :public toryengine::Component
{
public:
	void OnUpdate()
	{

		GetObject()->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.05f * move_dir, 0.0f, 0.0f));
		if (GetObject()->GetComponent<toryengine::Transform>()->GetPosition().x > 4.0f
			|| GetObject()->GetComponent<toryengine::Transform>()->GetPosition().x < -4.0f)
		{
			move_dir *= -1;
		}
		//GetObject()->GetComponent<toryengine::BoxCollider>()->Test();
		if (GetObject()->GetComponent<toryengine::BoxCollider>()->isBoxColliding() )
		{
			move_dir *= -1;
		}
		//if (glm::distance(lastPos, GetObject()->GetComponent<toryengine::Transform>()->GetPosition())>0.2f)
		//{
		//	GetObject()->GetComponent<toryengine::Transform>()->SetLocalPosition(lastPos);
		//}
		//lastPos = GetObject()->GetComponent<toryengine::Transform>()->GetPosition();
	}
private:
	float move_dir = -1;
	glm::vec3 lastPos;
};

int main()
{
	std::cout << "Hello World" << std::endl;

	std::shared_ptr<toryengine::Root> root = toryengine::Root::Initalize();

	//std::shared_ptr<toryengine::Object> cat = root->AddObject();

	std::shared_ptr<toryengine::Object> cube = root->AddObject();
	std::shared_ptr<toryengine::Object> cube2 = root->AddObject();

	//DELETE std::shared_ptr<toryengine::Resources> resources = std::make_shared<toryengine::Resources>();

	std::shared_ptr<toryengine::Sound> s = std::make_shared<toryengine::Sound>("../Crush8-Bit.ogg");
	s->Play();

	//std::shared_ptr<TestScreen> ts = cat->AddComponent<TestScreen>("Green");

	//object->AddComponent<toryengine::BoxCollider>();
	//object->GetComponent<toryengine::BoxCollider>()->SetSize(glm::vec3(1.0f, 1.0f, 1.0f));


	std::shared_ptr<toryengine::MeshRenderer> mrCube = cube->AddComponent < toryengine::MeshRenderer>();
	std::shared_ptr<toryengine::MeshRenderer> mrCube2 = cube2->AddComponent < toryengine::MeshRenderer>();

	//std::shared_ptr<toryengine::MeshRenderer> mr = cat->AddComponent<toryengine::MeshRenderer>();

	//DELETEstd::shared_ptr<toryengine::MeshRenderer>mr2 = object->GetComponent<toryengine::MeshRenderer>();
	//DELETEstd::shared_ptr<toryengine::Resources> temp = root->GetResources();

	//mr->SetTexture(root->GetResources()->Load<toryengine::Texture>("../texture.jpg"));//"texture.jpg"));
	//mr->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../curuthers.obj"));
	//mr->SetTexture(root->GetResources()->Load<toryengine::Texture>("../curuthers_diffuse.png"));

	//cat->AddComponent<toryengine::BoxCollider>();

	mrCube->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../cube.obj"));
	mrCube->SetTexture(root->GetResources()->Load<toryengine::Texture>("../curuthers_diffuse.png"));

	mrCube2->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../cube.obj"));
	mrCube2->SetTexture(root->GetResources()->Load<toryengine::Texture>("../texture.jpg"));

	//cat->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.0f, 0.0f, -10.0f));
	
	cube->GetComponent<toryengine::Transform>()->Translate(glm::vec3(3.0f, -2.0f, 2.0f));	//left-right,up-down, forward, ba
	cube2->GetComponent<toryengine::Transform>()->Translate(glm::vec3(-3.0f, -2.0f, 2.0f));

	cube->AddComponent<toryengine::BoxCollider>();
	cube->GetComponent<toryengine::BoxCollider>()->SetSize(glm::vec3(1.0f, 1.0f, 1.0f));
	cube->GetComponent<toryengine::BoxCollider>()->Test();
	cube->AddComponent<MoveCube>();

	

	cube2->AddComponent<toryengine::BoxCollider>();
	cube2->GetComponent<toryengine::BoxCollider>()->SetSize(glm::vec3(1.0f, 1.0f, 1.0f));
	cube2->AddComponent < MoveCube2>();



	//object->GetComponent<toryengine::BoxCollider>()->SetSize(glm::vec3(1.0f, 1.0f, 1.0f));


	//DELETEstd::vector<std::shared_ptr<toryengine::Object>> output;
	//DELETEroot->GetObjectsWithComponent<toryengine::MeshRenderer>(output);


	root->Start();
	return 0;
}