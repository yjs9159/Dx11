#pragma once
#include "..\\YamYamEngine_SOURCE\\yjsSceneManager.h"
#include "yjsPlayScene.h"


//#ifdef  _DEBUG
//#pragma comment(lib, "..\\x64\\Debug\\YamYamEngine_Windows.lib")
//#else
//#pragma comment(lib, "..\\x64\\Release\\YamYamEngine_Windows.lib")
//#endif //  _DEBUG

namespace yjs
{
	void InitializeScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}