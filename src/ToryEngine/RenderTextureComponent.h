#include "Component.h"

namespace toryengine
{
	class RenderTexture;
	class ShaderProgram;

	class RenderTextureComponent :public Component
	{

	public:
		void OnInit();
		void OnUpdate();
		void OnDraw();
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