#pragma once
#include "yjsComponent.h"
#include "yjsMesh.h"
#include "yjsShader.h"


namespace yjs
{
	using namespace graphics;

	class MeshRenderer : public Component
	{
	public:
		MeshRenderer();
		~MeshRenderer();
		
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetMesh(Mesh* mesh) { mMesh = mesh; }
		void SetShader(Shader* shader) { mShader = shader; }

	private:
		Mesh* mMesh;
		Shader* mShader;
	};
}
