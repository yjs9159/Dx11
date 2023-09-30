#pragma once
#include "yjsEnums.h"
#include "CommonInclude.h"
#include "yjsEngine.h"
#include "yjsMath.h"
#include "yjsGraphicsDevice_DX11.h"

#include "yjsMesh.h"
#include "yjsShader.h"
#include "yjsConstantBuffer.h"

using namespace yjs::graphics;
using namespace yjs::enums;
using namespace yjs::math;

namespace yjs::renderer
{
	struct Vertex
	{
		Vector3 pos;
		Vector4 color;
	};

	CBUFFER(TransformCB, CBSLOT_TRANSFORM)
	{
		Vector3 pos;
		int padd1;

		Vector3 scale;
		int padd2;
	};

	extern Mesh* mesh;
	extern Shader* shader;
	extern ConstantBuffer* constantBuffers[];

	// Initialize the renderer
	void Initialize();
	void Release();
}
