#include "yjsRenderer.h"
#include "yjsApplication.h"
#include "yjsResources.h"

extern yjs::Application application;



namespace yjs::renderer
{

	D3D11_INPUT_ELEMENT_DESC InputLayouts[2];
	Mesh* mesh = nullptr;
	Shader* shader = nullptr;
	ConstantBuffer* constantBuffers[(UINT)graphics::eCBType::End];
	
	void SetUpStates()
	{

	}

	void LoadBuffer()
	{
		std::vector<Vertex> vertexes;
		vertexes.resize(3);
		vertexes[0].pos = Vector3(0.f, 0.5f, 0.f);
		vertexes[0].color = Vector4(0.f, 1.f, 0.f, 1.f);

		vertexes[1].pos = Vector3(0.5f, -0.5f, 0.f);
		vertexes[1].color = Vector4(1.f, 0.f, 0.f, 1.f);

		vertexes[2].pos = Vector3(-0.5f, -0.5f, 0.f);
		vertexes[2].color = Vector4(0.f, 0.f, 1.f, 1.f);

		std::vector<UINT> indexes;
		indexes.push_back(0);
		indexes.push_back(2);
		indexes.push_back(3);

		indexes.push_back(0);
		indexes.push_back(1);
		indexes.push_back(2);

		// Triangle Vertex Buffer
		mesh->CreateVertexBuffer(vertexes.data(), 3);
		mesh->CreateIndexBuffer(indexes.data(), indexes.size());
		Resources::Insert(L"TriangleMesh", mesh);
		
		constantBuffers[(UINT)graphics::eCBType::Transform] = new ConstantBuffer();
		constantBuffers[(UINT)graphics::eCBType::Transform]->Create(sizeof(TransformCB));
		//mesh->CreateConstantBuffer(nullptr, sizeof(Vector4));
	}

	void LoadShader()
	{
		shader->Create(eShaderStage::VS, L"TriangleVS.hlsl", "VS_Test");
		shader->Create(eShaderStage::PS, L"TrianglePS.hlsl", "PS_Test");
		Resources::Insert(L"TriangleShader", shader);
		//GetDevice()->CreateShader(eShaderStage::NONE);
		//GetDevice()->CreateVertexShader();`
				// Input layout ���� ���� ����
		InputLayouts[0].AlignedByteOffset = 0;
		InputLayouts[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
		InputLayouts[0].InputSlot = 0;
		InputLayouts[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		InputLayouts[0].SemanticName = "POSITION";
		InputLayouts[0].SemanticIndex = 0;

		InputLayouts[1].AlignedByteOffset = 12;
		InputLayouts[1].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
		InputLayouts[1].InputSlot = 0;
		InputLayouts[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		InputLayouts[1].SemanticName = "COLOR";
		InputLayouts[1].SemanticIndex = 0;

		GetDevice()->CreateInputLayout(InputLayouts, 2,
			shader->GetVSCode()->GetBufferPointer()
			, shader->GetVSCode()->GetBufferSize()
			, shader->GetInputLayoutAddressOf());
	}

	void Initialize()
	{
		mesh = new Mesh();
		shader = new Shader();

		LoadShader();
		SetUpStates();
		LoadBuffer();
	}

	void Release()
	{
		delete mesh;
		delete shader;

		delete constantBuffers[(UINT)graphics::eCBType::Transform];
		//triangleVertexBuffer->Release();
		//errorBlob->Release();
		//triangleVSBlob->Release();
		//triangleVSShader->Release();
		//trianglePSBlob->Release();
		//trianglePSShader->Release();
		//triangleLayout->Release();
	}
}