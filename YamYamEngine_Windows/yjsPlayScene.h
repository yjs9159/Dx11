#pragma once
#include "..\\YamYamEngine_SOURCE\\yjsScene.h"


namespace yjs
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		virtual ~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

	private:
	};
}
