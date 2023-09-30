#pragma once
#include "..\\YamYamEngine_SOURCE\\yjsScript.h"

namespace yjs
{

	class PlayerScript : public Script
	{
	public:
		PlayerScript();
		virtual ~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;
	};

}
