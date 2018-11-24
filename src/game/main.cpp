#include <ToryEngine/toryengine.h>
#include <iostream>


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

	//Make Render Texture Component
	//In OnInint make shader and render texture
	//shader program that draws to render texture instead of screen
	//std::shared_ptr<toryengine::ShaderProgram>lightKeyShader = std::make_shared<toryengine::ShaderProgram>("../resources/shaders/lightkeypass.vert", "../resources/shaders/lightkeypass.frag");
	//std::shared_ptr<toryengine::ShaderProgram>nullShader = std::make_shared<toryengine::ShaderProgram>("../resources/shaders/nullpass.vert", "../resources/shaders/nullpass.frag");
	//std::shared_ptr<toryengine::ShaderProgram>blurShader = std::make_shared<toryengine::ShaderProgram>("../resources/shaders/blur.vert", "../resources/shaders/blur.frag");
	//std::shared_ptr<toryengine::ShaderProgram>mergeShader = std::make_shared<toryengine::ShaderProgram>("../resources/shaders/mergepass.vert", "../resources/shaders/mergepass.frag");
	//

	//std::shared_ptr<toryengine::RenderTexture> rt = std::make_shared<toryengine::RenderTexture>(1024, 1024);
	//std::shared_ptr<toryengine::RenderTexture> lightKeyRt = std::make_shared<toryengine::RenderTexture>(1024, 1024);
	//std::shared_ptr<toryengine::RenderTexture> blurRt = std::make_shared<toryengine::RenderTexture>(1024, 1024);
	//std::shared_ptr<toryengine::RenderTexture> blur2Rt = std::make_shared<toryengine::RenderTexture>(1024, 1024);
	//std::shared_ptr<toryengine::RenderTexture> blur3Rt = std::make_shared<toryengine::RenderTexture>(1024, 1024);
	//std::shared_ptr<toryengine::RenderTexture> mergeRt = std::make_shared<toryengine::RenderTexture>(1024, 1024);

	//rt->Clear();

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


	//std::shared_ptr<toryengine::MeshRenderer> mr = cat->AddComponent<toryengine::MeshRenderer>();
	//mr->SetTexture(root->GetResources()->Load<toryengine::Texture>("../texture.jpg"));
	//mr->SetMesh(root->GetResources()->Load<toryengine::Mesh>("../curuthers.obj"));
	//mr->SetTexture(root->GetResources()->Load<toryengine::Texture>("../curuthers_diffuse.png"));
	//cat->GetComponent<toryengine::Transform>()->Translate(glm::vec3(0.0f, 0.0f, -10.0f));
	//cat->AddComponent<toryengine::BoxCollider>();
	//cat->GetComponent<toryengine::BoxCollider>()->SetSize();

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


//	lightKeyShader->SetUniform("in_Texture", std::dynamic_pointer_cast<toryengine::Texture>(rt));
	//lightKeyShader->Draw(lightKeyRt);

	//blurShader->SetUniform("in_Texture", std::dynamic_pointer_cast<toryengine::Texture>(lightKeyRt));
	//blurShader->Draw(blurRt);

	//blurShader->SetUniform("in_Texture", std::dynamic_pointer_cast<toryengine::Texture>(blurRt));
	//blurShader->Draw(blur2Rt);
	//
	//blurShader->SetUniform("in_Texture", std::dynamic_pointer_cast<toryengine::Texture>(blur2Rt));
	//blurShader->Draw(blur3Rt);

	//mergeShader->SetUniform("in_TextureA", std::dynamic_pointer_cast<toryengine::Texture>(rt));
	//mergeShader->SetUniform("in_TextureB", std::dynamic_pointer_cast<toryengine::Texture>(blur3Rt));
	//mergeShader->Draw(mergeRt);

	//nullShader->SetViewport(glm::vec4(0, 0, 800, 600));
	//nullShader->SetUniform("in_Texture", std::dynamic_pointer_cast<toryengine::Texture>(rt));

	root->Start();
	return 0;
}