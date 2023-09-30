#include "yjsPlayerScript.h"
#include "yjsTransform.h"
#include "yjsGameObject.h"
#include "yjsTransform.h"
#include "yjsTime.h"

namespace yjs
{

	PlayerScript::PlayerScript()
	{
	}

	PlayerScript::~PlayerScript()
	{
	}

	void PlayerScript::Initialize()
	{
	}

	void PlayerScript::Update()
	{
		GameObject* obj = GetOwner();
		Transform* tr = obj->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
		pos.x -= 0.1f * Time::DeltaTime();
		tr->SetPosition(pos);
	}

	void PlayerScript::LateUpdate()
	{
	}

	void PlayerScript::Render()
	{
	}

}
