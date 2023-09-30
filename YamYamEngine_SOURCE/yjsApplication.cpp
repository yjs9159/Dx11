#include "yjsApplication.h"
#include "yjsGraphicsDevice_DX11.h"

#include "yjsInput.h"
#include "yjsTime.h"
#include "yjsRenderer.h"
#include "yjsSceneManager.h"

using namespace yjs::graphics;

namespace yjs
{
	Application::~Application()
	{
		renderer::Release();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Initialize()
	{
		Time::Initialize();
		Input::Initialize();

		renderer::Initialize();
		SceneManager::Initialize();
	}

	void Application::Update()
	{
		Time::Update();
		Input::Update();

		SceneManager::Update();
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		graphicsDevice->Clear();
		graphicsDevice->AdjustViewport();

		Time::Render();
		SceneManager::Render();

		//graphicsDevice->Render();
		graphicsDevice->Present();
	}

	void Application::SetWindow(HWND hwnd, UINT width, UINT height)
	{
		if (graphicsDevice == nullptr)
		{
			mHwnd = hwnd;
			mWidth = width;
			mHegith = height;

			graphicsDevice = std::make_unique<GraphicsDevice_DX11>();
			yjs::graphics::GetDevice() = graphicsDevice.get();
			//ya::device = graphicsDevice.get();
		}

		RECT rt = { 0, 0, (LONG)width , (LONG)height };
		AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);
		SetWindowPos(mHwnd, nullptr, 0, 0, rt.right - rt.left, rt.bottom - rt.top, 0);
		ShowWindow(mHwnd, true);
		UpdateWindow(mHwnd);
	}
}
