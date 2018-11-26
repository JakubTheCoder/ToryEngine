#include "RenderTextureComponent.h"
#include "ShaderProgram.h"
#include "RenderTexture.h"

namespace toryengine
{
	void RenderTextureComponent::OnInit()
	{
		lightKeyShader = std::make_shared<ShaderProgram>("../resources/shaders/lightkeypass.vert", "../resources/shaders/lightkeypass.frag");
		nullShader = std::make_shared<ShaderProgram>("../resources/shaders/nullpass.vert", "../resources/shaders/nullpass.frag");
		blurShader = std::make_shared<ShaderProgram>("../resources/shaders/blur.vert", "../resources/shaders/blur.frag");
		mergeShader = std::make_shared<ShaderProgram>("../resources/shaders/mergepass.vert", "../resources/shaders/mergepass.frag");

		rt = std::make_shared<RenderTexture>(1024, 1024);
		lightKeyRt = std::make_shared<RenderTexture>(1024, 1024);
		blurRt = std::make_shared<RenderTexture>(1024, 1024);
		blur2Rt = std::make_shared<RenderTexture>(1024, 1024);
		blur3Rt = std::make_shared<RenderTexture>(1024, 1024);
		mergeRt = std::make_shared<RenderTexture>(1024, 1024);
	}
	void RenderTextureComponent::OnDraw()
	{
		lightKeyShader->
			
			
			
			
			
			("in_Texture", rt);
		lightKeyShader->Draw(lightKeyRt);

		blurShader->SetUniform("in_Texture", lightKeyRt);
		blurShader->Draw(blurRt);

		blurShader->SetUniform("in_Texture", blurRt);
		blurShader->Draw(blur2Rt);

		blurShader->SetUniform("in_Texture", blur2Rt);
		blurShader->Draw(blur3Rt);

		mergeShader->SetUniform("in_TextureA", rt);
		mergeShader->SetUniform("in_TexureB", blur3Rt);
		mergeShader->Draw(mergeRt);

		nullShader->SetViewport(glm::vec4(0, 0, 800, 600));
		nullShader->("in_Texture", rt);
	}
	void RenderTextureComponent::OnUpdate()
	{
		//rt->Clear();

	}
}