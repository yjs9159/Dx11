#pragma once
//#include "yjsGraphics.h"

namespace yjs::graphics
{
	//class GraphicsDevice
	//{
	//public:
	//	virtual ~GraphicsDevice() = default;

	//	virtual bool CreateSwapChain(const SwapChainDesc* desc, HWND hWnd, SwapChain* swapchain) = 0;
	//	virtual bool CreateBuffer(const GPUBufferDesc* desc, const void* initial_data, GPUBuffer* buffer) = 0;
	//	virtual bool CreateTexture(const TextureDesc* desc, const SubresourceData* initial_data, Texture* texture) = 0;
	//	virtual bool CreateSampler(const SamplerDesc* desc, Sampler* sampler) = 0;
	//	virtual bool CreateShader(eShaderStage stage, const void* shadercode, size_t shadercode_size, Shader* shader) = 0;

	//	virtual void Draw() = 0;
	//};

	// This is a helper to get access to a global device instance
	//	- The engine uses this, but it is not necessary to use a single global device object
	//	- This is not a lifetime managing object, just a way to globally expose a reference to an object by pointer
	//static GraphicsDevice* device = nullptr;
	//inline GraphicsDevice*& GetDevice()
	//{
	//	return device;
	//}
}

