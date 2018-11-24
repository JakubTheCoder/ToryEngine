#include <iostream>
#include <ToryEngine/toryengine.h>
#include "Player.h"



class MoveCube :public toryengine::Component
{
public :

	void OnUpdate()
	{

		if (toryengine::Keyboard::IsKeyDown(SDLK_w))
		{
			GetObject()->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.0f , 0.1f, 0.0f));
		}
		if (toryengine::Keyboard::IsKeyDown(SDLK_s))
		{
			GetObject()->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.0f, -0.1f, 0.0f));
		}
		if (toryengine::Keyboard::IsKeyDown(SDLK_d))
		{
			GetObject()->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.1f, 0.0f, 0.0f));
		}
		if (toryengine::Keyboard::IsKeyDown(SDLK_a))
		{
			GetObject()->GetComponent<toryengine::Transform>()->Translate(glm::vec3(-0.1f, 0.0f, 0.0f));
		}

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
			if (GetObject()->GetComponent<toryengine::BoxCollider>()->isBoxColliding())
			{
				move_dir *= -1;
			}
		}
	}
private:
	float move_dir = -1;
	glm::vec3 lastPos;
};

int main()
{
	std::cout << "Hello World" << std::endl;
	
	//Create and Initliaise Root
	std::shared_ptr<toryengine::Root> root = toryengine::Root::Initalize();

	//Camera
	std::shared_ptr<toryengine::Object> mainCamera = root->AddObject();
	mainCamera->AddComponent<toryengine::Camera>();
	mainCamera->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.0f, 0.0f, 10.0f));

	std::shared_ptr<toryengine::Object> sideCamera = root->AddObject();
	sideCamera->AddComponent<toryengine::Camera>();
	sideCamera->GetComponent<toryengine::Transform>()->Translate(glm::vec3(10.0f, 0.0f, 0.0f));
	//sideCamera->GetRoot()->SetCurrentCamera(sideCamera);
	sideCamera->GetComponent<toryengine::Transform>()->Rotate(glm::vec3(0.0f,90.0f,0.0f));	//ROTATION WORKS AS IF YOU PUT A POLE THROUGH THE axis 

	mainCamera->GetRoot()->SetCurrentCamera(mainCamera);

	std::shared_ptr<toryengine::Object>player = root->AddObject();
	player->AddComponent<Player>();
	player->AddComponent<toryengine::Camera>();
	player->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.0f, 0.0f, 10.0f));
	player->GetRoot()->SetCurrentCamera(player);


	//Create Objcets
	std::shared_ptr<toryengine::Object> cube = root->AddObject();
	std::shared_ptr<toryengine::MeshRenderer> mrCube = cube->AddComponent < toryengine::MeshRenderer>();
	mrCube->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../cube.obj"));
	mrCube->SetTexture(root->GetResources()->Load<toryengine::Texture>("../curuthers_diffuse.png"));
	cube->GetComponent<toryengine::Transform>()->Translate(glm::vec3(-4.0f, -1.0f, 0.0f));
	cube->AddComponent<toryengine::BoxCollider>();
	cube->AddComponent < toryengine::MeshCollider>();
	cube->AddComponent<MoveCube>();

	//cube->GetComponent<toryengine::MeshRenderer>()->GetShader()->Draw(rt, cube->GetComponent<toryengine::M>()->GetShape());
	//cube->GetComponent<toryengine::MeshRenderer>()->GetShader()->Draw(rt, cube->GetComponent<toryengine::MeshRenderer>()->GetMesh()->GetShape());


	std::shared_ptr<toryengine::Object> cube2 = root->AddObject();
	std::shared_ptr<toryengine::MeshRenderer> mrCube2 = cube2->AddComponent < toryengine::MeshRenderer>();
	mrCube2->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../cube.obj"));
	mrCube2->SetTexture(root->GetResources()->Load<toryengine::Texture>("../texture.jpg"));
	cube2->GetComponent<toryengine::Transform>()->Translate(glm::vec3(4.0f, -1.0f,0.0f));
	//cube2->AddComponent<toryengine::MeshCollider>();
	cube2->AddComponent < MoveCube2>();
	//cube2->GetComponent<toryengine::MeshRenderer>()->GetShader()->Draw(rt, cube->GetComponent<toryengine::MeshRenderer>()->GetMesh()->GetShape());
	//Sound
	std::shared_ptr<toryengine::Sound> s = std::make_shared<toryengine::Sound>("../Crush8-Bit.ogg");
	s->Play();

	root->Start();
	return 0;
}