#pragma once
#include "yjsEnums.h"
#include "yjsEntity.h"
#include "yjsLayer.h"

namespace yjs
{
	using namespace yjs::enums;

	class Scene : public Entity
	{
	public:
		Scene();
		virtual ~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		Layer* GetLayer(UINT index) { return& mLayers[index]; }
		void AddGameObject(GameObject* gameObject, UINT layerIndex);

	private:
		Layer mLayers[LAYER::MAX];
	};
}
