#include <ToryEngine/toryengine.h>
#include <iostream>
//Where to put Render Textures? and how to place them in Mesh Renderer instead of the default shader, pass in what shader you want you use? meaning they have to be created in main / root maybe?
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

		if (toryengine::Keyboard::IsKeyDown(SDLK_w))
		{
			GetObject()->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.0f , 0.5f*move_dir, 0.0f));
		}
		/*GetObject()->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.05f * move_dir, 0.0f, 0.0f));
		if (GetObject()->GetComponent<toryengine::Transform>()->GetPosition().x > 4.0f
			|| GetObject()->GetComponent<toryengine::Transform>()->GetPosition().x < -4.0f)
		{
			move_dir *= -1;
		}
		if (GetObject()->GetComponent<toryengine::BoxCollider>()->isBoxColliding())
		{
			move_dir *= -1;
		}*/
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
	
	//Create and Initliaise Root
	std::shared_ptr<toryengine::Root> root = toryengine::Root::Initalize();


	std::shared_ptr<toryengine::ShaderProgram>lightKeyShader = std::make_shared<toryengine::ShaderProgram>("../resources/shaders/lightkeypass.vert", "../resources/shaders/lightkeypass.frag");
	std::shared_ptr<toryengine::ShaderProgram>nullShader = std::make_shared<toryengine::ShaderProgram>("../resources/shaders/nullpass.vert", "../resources/shaders/nullpass.frag");
	std::shared_ptr<toryengine::ShaderProgram>blurShader = std::make_shared<toryengine::ShaderProgram>("../resources/shaders/blur.vert", "../resources/shaders/blur.frag");
	std::shared_ptr<toryengine::ShaderProgram>mergeShader = std::make_shared<toryengine::ShaderProgram>("../resources/shaders/mergepass.vert", "../resources/shaders/mergepass.frag");

	std::shared_ptr<toryengine::RenderTexture> rt = std::make_shared<toryengine::RenderTexture>(1024, 1024);
	std::shared_ptr<toryengine::RenderTexture> lightKeyRt = std::make_shared<toryengine::RenderTexture>(1024, 1024);
	std::shared_ptr<toryengine::RenderTexture> blurRt = std::make_shared<toryengine::RenderTexture>(1024, 1024);
	std::shared_ptr<toryengine::RenderTexture> blur2Rt = std::make_shared<toryengine::RenderTexture>(1024, 1024);
	std::shared_ptr<toryengine::RenderTexture> blur3Rt = std::make_shared<toryengine::RenderTexture>(1024, 1024);
	std::shared_ptr<toryengine::RenderTexture> mergeRt = std::make_shared<toryengine::RenderTexture>(1024, 1024);



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

	//Create Objcets
	//std::shared_ptr<toryengine::Object> cat = root->AddObject();
	std::shared_ptr<toryengine::Object> cube = root->AddObject();
	std::shared_ptr<toryengine::MeshRenderer> mrCube = cube->AddComponent < toryengine::MeshRenderer>();
	mrCube->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../cube.obj"));
	mrCube->SetTexture(root->GetResources()->Load<toryengine::Texture>("../curuthers_diffuse.png"));
	cube->GetComponent<toryengine::Transform>()->Translate(glm::vec3(-4.0f, -1.0f, 0.0f));
	cube->AddComponent<toryengine::BoxCollider>()->SetSize(glm::vec3(1.0f,1.0f,1.0f));
	cube->GetComponent<toryengine::BoxCollider>()->Test();
	cube->AddComponent<MoveCube>();
	//cube->GetComponent<toryengine::MeshRenderer>()->GetShader()->Draw(rt, cube->GetComponent<toryengine::Mesh>()->GetShape());
	cube->GetComponent<toryengine::MeshRenderer>()->GetShader()->Draw(rt, cube->GetComponent<toryengine::Mesh>()->GetShape());

	std::shared_ptr<toryengine::Object> cube2 = root->AddObject();
	std::shared_ptr<toryengine::MeshRenderer> mrCube2 = cube2->AddComponent < toryengine::MeshRenderer>();
	mrCube2->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../cube.obj"));
	mrCube2->SetTexture(root->GetResources()->Load<toryengine::Texture>("../texture.jpg"));
	cube2->GetComponent<toryengine::Transform>()->Translate(glm::vec3(4.0f, -1.0f,0.0f));
	cube2->AddComponent<toryengine::BoxCollider>()->SetSize(glm::vec3(1.0f, 1.0f, 1.0f));
	cube2->AddComponent < MoveCube2>();

	//Sound
	std::shared_ptr<toryengine::Sound> s = std::make_shared<toryengine::Sound>("../Crush8-Bit.ogg");
	s->Play();

	//std::shared_ptr<TestScreen> ts = cat->AddComponent<TestScreen>("Green");

	//object->AddComponent<toryengine::BoxCollider>();
	//object->GetComponent<toryengine::BoxCollider>()->SetSize(glm::vec3(1.0f, 1.0f, 1.0f));


	//std::shared_ptr<toryengine::MeshRenderer> mr = cat->AddComponent<toryengine::MeshRenderer>();

	//mr->SetTexture(root->GetResources()->Load<toryengine::Texture>("../texture.jpg"));//"texture.jpg"));
	//mr->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../curuthers.obj"));
	//mr->SetTexture(root->GetResources()->Load<toryengine::Texture>("../curuthers_diffuse.png"));

	//cat->AddComponent<toryengine::BoxCollider>();


	//cat->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.0f, 0.0f, -10.0f));
	
		//left-right,up-down, forward, ba
	

	//object->GetComponent<toryengine::BoxCollider>()->SetSize(glm::vec3(1.0f, 1.0f, 1.0f));


	//DELETEstd::vector<std::shared_ptr<toryengine::Object>> output;
	//DELETEroot->GetObjectsWithComponent<toryengine::MeshRenderer>(output);
	lightKeyShader->SetUniform("in_Texture", rt);
	//std::dynamic_pointer_cast<
	lightKeyShader->Draw(lightKeyRt);

	root->Start();
	return 0;
}