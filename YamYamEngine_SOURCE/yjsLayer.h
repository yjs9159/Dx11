#pragma once
#include "yjsEntity.h"
#include "yjsGameObject.h"

namespace yjs
{
	class Layer : public Entity
	{
	public:
		Layer();
		virtual ~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		void AddGameObject(GameObject*  gameObject);

	private:
		std::vector<GameObject*> mGameObjects;
	};
}
