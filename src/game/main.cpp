#include <iostream>
#include <time.h>
#include <ToryEngine/toryengine.h>
#include "Player.h"
#include "Platform.h"
#include "DeathCube.h"
class MoveCube :public toryengine::Component
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
		if (GetObject()->GetComponent<toryengine::BoxCollider>()->isBoxColliding())
		{
			move_dir *= -1;
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
		}

	}
private:
	float move_dir = -1;
};

int main()
{
	srand(time(NULL));
	std::cout << "Hello World" << std::endl;

	//Create and Initliaise Root
	std::shared_ptr<toryengine::Root> root = toryengine::Root::Initalize();

	//Camera
	std::shared_ptr<toryengine::Object> mainCamera = root->AddObject();
	mainCamera->AddComponent<toryengine::Camera>();
	mainCamera->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.0f, 0.0f, 50.0f));

	std::shared_ptr<toryengine::Object> sideCamera = root->AddObject();
	sideCamera->AddComponent<toryengine::Camera>();
	sideCamera->GetComponent<toryengine::Transform>()->Translate(glm::vec3(10.0f, 0.0f, 0.0f));
	//sideCamera->GetRoot()->SetCurrentCamera(sideCamera);
	sideCamera->GetComponent<toryengine::Transform>()->Rotate(glm::vec3(0.0f, 90.0f, 0.0f));	//ROTATION WORKS AS IF YOU PUT A POLE THROUGH THE axis 

	mainCamera->GetRoot()->SetCurrentCamera(mainCamera);

	std::shared_ptr<toryengine::Object>player = root->AddObject();
	player->AddComponent<Player>();
	std::shared_ptr<toryengine::MeshRenderer> playerMr = player->AddComponent<toryengine::MeshRenderer>();
	playerMr->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../assets/cube.obj"));
	playerMr->SetTexture(root->GetResources()->Load<toryengine::Texture>("../assets/player.png"));
	player->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.0f, 1.0f, -5.0f));
	player->AddComponent<toryengine::BoxCollider>();


	//std::shared_ptr<toryengine::Object>platform = root->AddObject();
	//std::shared_ptr<toryengine::MeshRenderer> platformMr = platform->AddComponent<toryengine::MeshRenderer>();
	//platformMr->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../assets/platform.obj"));
	//platformMr->SetTexture(root->GetResources()->Load<toryengine::Texture>("../assets/platform.jpg"));
	//platform->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.0f, -3.0f, -5.0f));
	//platform->AddComponent<toryengine::BoxCollider>();
	//platform->AddComponent<Platform>();

	//std::shared_ptr<toryengine::Object> platform = root->AddObject();
	//std::shared_ptr<toryengine::MeshRenderer> platformMr = platform->AddComponent<toryengine::MeshRenderer>();
	//platformMr->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../assets/platform.obj"));
	//platformMr->SetTexture(root->GetResources()->Load<toryengine::Texture>("../assets/platform.jpg"));
	//platform->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.0f, -1.0f, -5.0f));
	//platform->AddComponent<toryengine::BoxCollider>();
	
	//Create Platforms
	//Platform 1
	int platformSize;
	std::shared_ptr<toryengine::Object>platform1 = root->AddObject();
	std::shared_ptr<toryengine::MeshRenderer> platformMr1 = platform1->AddComponent<toryengine::MeshRenderer>();
	platformSize = rand() % 3;

	if(platformSize == 0){ platformMr1->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../assets/smallPlatform.obj")); }
	if(platformSize == 1){ platformMr1->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../assets/mediumPlatform.obj")); }
	if(platformSize == 2){ platformMr1->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../assets/bigPlatform.obj")); }
	platformMr1->SetTexture(root->GetResources()->Load<toryengine::Texture>("../assets/platform.jpg"));
	
	platform1->AddComponent<Platform>();
	platform1->GetComponent<toryengine::Transform>()->Translate(glm::vec3(platform1->GetComponent<Platform>()->GetPlatformPos(), -5.0f, -5.0f));
	platform1->AddComponent<toryengine::BoxCollider>();

	//Platform 2
	std::shared_ptr<toryengine::Object>platform2 = root->AddObject();
	std::shared_ptr<toryengine::MeshRenderer> platformMr2 = platform2->AddComponent<toryengine::MeshRenderer>();
	platformSize = rand() % 3;

	if (platformSize == 0) { platformMr2->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../assets/smallPlatform.obj")); }
	if (platformSize == 1) { platformMr2->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../assets/mediumPlatform.obj")); }
	if (platformSize == 2) { platformMr2->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../assets/bigPlatform.obj")); }
	platformMr2->SetTexture(root->GetResources()->Load<toryengine::Texture>("../assets/platform.jpg"));

	platform2->AddComponent<Platform>();
	platform2->GetComponent<toryengine::Transform>()->Translate(glm::vec3(platform2->GetComponent<Platform>()->GetPlatformPos(), 0.0f, -5.0f));
	platform2->AddComponent<toryengine::BoxCollider>();

	//Platform 3
	std::shared_ptr<toryengine::Object>platform3 = root->AddObject();
	std::shared_ptr<toryengine::MeshRenderer> platformMr3 = platform3->AddComponent<toryengine::MeshRenderer>();
	platformSize = rand() % 3;

	if (platformSize == 0) { platformMr3->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../assets/smallPlatform.obj")); }
	if (platformSize == 1) { platformMr3->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../assets/mediumPlatform.obj")); }
	if (platformSize == 2) { platformMr3->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../assets/bigPlatform.obj")); }
	platformMr3->SetTexture(root->GetResources()->Load<toryengine::Texture>("../assets/platform.jpg"));

	platform3->AddComponent<Platform>();
	platform3->GetComponent<toryengine::Transform>()->Translate(glm::vec3(platform3->GetComponent<Platform>()->GetPlatformPos(), 5.0f, -5.0f));
	platform3->AddComponent<toryengine::BoxCollider>();

	//Platform 4
	std::shared_ptr<toryengine::Object>platform4 = root->AddObject();
	std::shared_ptr<toryengine::MeshRenderer> platformMr4 = platform4->AddComponent<toryengine::MeshRenderer>();
	platformSize = rand() % 3;

	if (platformSize == 0) { platformMr4->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../assets/smallPlatform.obj")); }
	if (platformSize == 1) { platformMr4->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../assets/mediumPlatform.obj")); }
	if (platformSize == 2) { platformMr4->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../assets/bigPlatform.obj")); }
	platformMr4->SetTexture(root->GetResources()->Load<toryengine::Texture>("../assets/platform.jpg"));

	platform4->AddComponent<Platform>();
	platform4->GetComponent<toryengine::Transform>()->Translate(glm::vec3(platform4->GetComponent<Platform>()->GetPlatformPos(), 10.0f, -5.0f));
	platform4->AddComponent<toryengine::BoxCollider>();

	//Platform 5
	std::shared_ptr<toryengine::Object>platform5 = root->AddObject();
	std::shared_ptr<toryengine::MeshRenderer> platformMr5 = platform5->AddComponent<toryengine::MeshRenderer>();
	platformSize = rand() % 3;

	if (platformSize == 0) { platformMr5->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../assets/smallPlatform.obj")); }
	if (platformSize == 1) { platformMr5->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../assets/mediumPlatform.obj")); }
	if (platformSize == 2) { platformMr5->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../assets/bigPlatform.obj")); }
	platformMr5->SetTexture(root->GetResources()->Load<toryengine::Texture>("../assets/platform.jpg"));

	platform5->AddComponent<Platform>();
	platform5->GetComponent<toryengine::Transform>()->Translate(glm::vec3(platform5->GetComponent<Platform>()->GetPlatformPos(), 15.0f, -5.0f));
	platform5->AddComponent<toryengine::BoxCollider>();


	//Create Objcets
	//std::shared_ptr<toryengine::Object> cube = root->AddObject();
	//std::shared_ptr<toryengine::MeshRenderer> mrCube = cube->AddComponent<toryengine::MeshRenderer>();
	//mrCube->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../assets/platform.obj"));
	//mrCube->SetTexture(root->GetResources()->Load<toryengine::Texture>("../assets/curuthers_diffuse.png"));
	//cube->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.0f, -5.0f, -5.0f));
	//cube->AddComponent<toryengine::BoxCollider>();
	////cube->AddComponent < toryengine::MeshCollider>();
	////cube->AddComponent<MoveCube>();
	//cube->AddComponent<Platform>();
	////cube->AddComponent<toryengine::RenderTextureComponent>();
	////cube->GetComponent<toryengine::MeshRenderer>()->GetShader()->Draw(cube->GetComponent<toryengine::RenderTextureComponent>()->GetRenderTexture(), cube->GetComponent<toryengine::MeshRenderer>()->GetMesh()->GetShape());
	////cube->GetComponent<toryengine::MeshRenderer>()->GetShader()->Draw(cube->GetComponent<toryengine::RenderTextureComponent>()->GetRenderTexture()//, cube->GetComponent<toryengine::MeshRenderer>()->GetMesh()->GetShape());


	//std::shared_ptr<toryengine::Object> cube2 = root->AddObject();
	//std::shared_ptr<toryengine::MeshRenderer> mrCube2 = cube2->AddComponent < toryengine::MeshRenderer>();
	//mrCube2->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../assets/platform.obj"));
	//mrCube2->SetTexture(root->GetResources()->Load<toryengine::Texture>("../assets/platform.jpg"));
	//cube2->GetComponent<toryengine::Transform>()->Translate(glm::vec3(-4.0f, 0.0f, -5.0f));
	//cube2->AddComponent<toryengine::BoxCollider>();
	////cube2->AddComponent < MoveCube2>();
	//cube2->AddComponent<Platform>();
	////cube2->AddComponent<toryengine::RenderTextureComponent>();
	
	std::shared_ptr<toryengine::Object>deathCube = root->AddObject();
	std::shared_ptr<toryengine::MeshRenderer> deathCubeMr = deathCube->AddComponent < toryengine::MeshRenderer>();
	deathCubeMr->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../assets/platform.obj"));
	deathCubeMr->SetTexture(root->GetResources()->Load<toryengine::Texture>("../assets/platform.jpg"));
	deathCube->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.0f,-15.0f,-5.0f));
	deathCube->AddComponent<toryengine::BoxCollider>();
	deathCube->AddComponent<DeathCube>();
	//cube2->GetComponent<toryengine::MeshRenderer>()->GetShader()->
		//Draw(cube2->GetComponent<toryengine::RenderTextureComponent>()->GetRenderTexture(), cube->GetComponent<toryengine::MeshRenderer>()->GetMesh()->GetShape());

	//Sound
	std::shared_ptr<toryengine::Sound> s = std::make_shared<toryengine::Sound>("../assets/Crush8-Bit.ogg");
	s->Play();

	root->Start();
	return 0;
}