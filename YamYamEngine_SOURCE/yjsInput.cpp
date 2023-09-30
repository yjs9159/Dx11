#include "yjsInput.h"
#include "yjsApplication.h"

extern yjs::Application application;

namespace yjs
{
	std::vector<Input::Key> Input::mKeys;
	Vector2 Input::mMousPosition;
	int ASCII[(UINT)KEY_CODE::END] =
	{
		//Alphabet
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',

		//Special Key
		VK_RETURN, VK_ESCAPE, VK_LSHIFT, VK_LMENU, VK_LCONTROL,
		VK_SPACE, VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN,
		VK_LBUTTON, VK_RBUTTON,

		//Num Pad
		VK_NUMPAD0, VK_NUMPAD1, VK_NUMPAD2,
		VK_NUMPAD3, VK_NUMPAD4, VK_NUMPAD5,
		VK_NUMPAD6, VK_NUMPAD7, VK_NUMPAD8,
		VK_NUMPAD9,

		//Num Line
		'0', '1', '2', '3', '4', '5',
		'6', '7', '8', '9',
	};


	void Input::Initialize()
	{
		for (UINT i = 0; i < (UINT)KEY_CODE::END; i++)
		{
			Key key;
			key.eType = (KEY_CODE)i;
			key.eState = KEY_STATE::NONE;
			key.bPressed = false;

			mKeys.push_back(key);
		}
	}

	void Input::Update()
	{
		if (GetFocus())
		{
			//KEY
			for (UINT i = 0; i < (UINT)KEY_CODE::END; ++i)
			{
				// �ش�Ű�� ���� �����ִ�.
				if (GetAsyncKeyState(ASCII[i]) & 0x8000)
				{
					// ���� �����ӿ��� ���� �־���.
					if (mKeys[i].bPressed)
						mKeys[i].eState = KEY_STATE::PRESSED;
					else
						mKeys[i].eState = KEY_STATE::DOWN;

					mKeys[i].bPressed = true;
				}
				else // �ش�Ű�� ���� �ȴ����ִ�.
				{
					// ���� �����ӿ��� ���� �־���.
					if (mKeys[i].bPressed)
						mKeys[i].eState = KEY_STATE::UP;
					else // ���� �����ӿ��� �ȴ��� �־���.
						mKeys[i].eState = KEY_STATE::NONE;

					mKeys[i].bPressed = false;
				}
			}

			POINT mousePos = {};
			GetCursorPos(&mousePos);
			ScreenToClient(application.GetHwnd(), &mousePos);
			mMousPosition.x = mousePos.x;
			mMousPosition.y = mousePos.y;
		}
		else
		{
			for (UINT i = 0; i < (UINT)KEY_CODE::END; ++i)
			{
				if (KEY_STATE::DOWN == mKeys[i].eState || KEY_STATE::PRESSED == mKeys[i].eState)
					mKeys[i].eState = KEY_STATE::UP;
				else if (KEY_STATE::UP == mKeys[i].eState)
					mKeys[i].eState = KEY_STATE::NONE;

				mKeys[i].bPressed = false;
			}
		}

	}
}