#pragma once
#include "stdafx.h"

namespace FrameDX
{
	// Forward declaration to prevent dependency loop
	class Device;

	class Texture
	{
	public:
		struct Description
		{
			Description()
			{
				SizeX = 0;
				SizeY = 0;
				Format = DXGI_FORMAT_R8G8B8A8_UNORM;
				MSAACount = 0;
				MSAAQuality = 0;
			}

			uint32_t SizeX;
			uint32_t SizeY;
			DXGI_FORMAT Format;
			enum class UsageType 
			{
				NoCPUAccess        = DXGI_CPU_ACCESS_NONE,
				CPUAccessDynamic   = DXGI_CPU_ACCESS_DYNAMIC,
				CPUAccessReadWrite = DXGI_CPU_ACCESS_READ_WRITE,
				CPUAccessScratch   = DXGI_CPU_ACCESS_SCRATCH,
				ShaderResource     = DXGI_USAGE_SHADER_INPUT,
				RenderTarget       = DXGI_USAGE_RENDER_TARGET_OUTPUT,
				UnorderedAccess    = DXGI_USAGE_UNORDERED_ACCESS
			} Usage;
		
			uint32_t MSAACount;
			uint32_t MSAAQuality;
		};

	private:

	};
}