#include "Component.h"

namespace toryengine
{
	class RenderTexture;
	class ShaderProgram;
	/*!
		Stores render textures and shaders for render textures and post processing + blur
	*/
	class RenderTextureComponent :public Component
	{

	public:
		void OnInit();	///<Initialization function for Render Texture Component
		void OnUpdate();///<Update function for Render Texture Component
		void OnDraw();	///<Draw function for Render Texture Component

		std::shared_ptr<RenderTexture> GetRenderTexture() { return rt; }	///<returns render texture
	private:

		std::shared_ptr<RenderTexture> rt;
		std::shared_ptr<RenderTexture> lightKeyRt;
		std::shared_ptr<RenderTexture> blurRt;
		std::shared_ptr<RenderTexture> blur2Rt;
		std::shared_ptr<RenderTexture> blur3Rt;
		std::shared_ptr<RenderTexture> mergeRt;

		std::shared_ptr<ShaderProgram>lightKeyShader;
		std::shared_ptr<ShaderProgram>nullShader;
		std::shared_ptr<ShaderProgram>blurShader;
		std::shared_ptr<ShaderProgram>mergeShader;
	};
}