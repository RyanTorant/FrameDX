#include "stdafx.h"
#include "Texture.h"
#include "..\Device\Device.h"
#include "..\Core\Log.h"

using namespace FrameDX;

StatusCode FrameDX::Texture::CreateSimpleSRV(Device * OwnerDevice)
{
	// Device version 3 required to create a SRV1
	if(Version == 0 || OwnerDevice->GetDeviceVersion() < 3)
	{
		D3D11_SHADER_RESOURCE_VIEW_DESC srv_desc;
		FillSRVDescription(&srv_desc);

		LogCheckWithReturn(OwnerDevice->GetDevice()->CreateShaderResourceView(TextureResource,&srv_desc,&SRV),LogCategory::Error);
	}
	else if(Version == 1)
	{
		D3D11_SHADER_RESOURCE_VIEW_DESC1 srv_desc;
		FillSRVDescription1(&srv_desc);

		LogCheckWithReturn(OwnerDevice->GetDevice3()->CreateShaderResourceView1(TextureResource,&srv_desc,(ID3D11ShaderResourceView1**)&SRV),LogCategory::Error);
	}
	else
		return StatusCode::InvalidArgument;

	return StatusCode::Ok;
}

StatusCode FrameDX::Texture::CreateSimpleUAV(Device * OwnerDevice)
{
	// Device version 3 required to create an UAV1
	if(Version == 0 || OwnerDevice->GetDeviceVersion() < 3)
	{
		D3D11_UNORDERED_ACCESS_VIEW_DESC uav_desc;


		LogCheckWithReturn(OwnerDevice->GetDevice()->CreateUnorderedAccessView(TextureResource,&uav_desc,&UAV),LogCategory::Error);
	}
	else if(Version == 1)
	{
		D3D11_UNORDERED_ACCESS_VIEW_DESC1 uav_desc;
		uav_desc.Format = Desc.Format;
		uav_desc.Texture2D.MipSlice = 0;
		uav_desc.Texture2D.PlaneSlice = 0;
		uav_desc.ViewDimension = D3D11_UAV_DIMENSION_TEXTURE2D;

		LogCheckWithReturn(OwnerDevice->GetDevice3()->CreateUnorderedAccessView1(TextureResource,&uav_desc,(ID3D11UnorderedAccessView1**)&UAV),LogCategory::Error);
	}
	else
		return StatusCode::InvalidArgument;
	return StatusCode::Ok;
}

StatusCode FrameDX::Texture::CreateSimpleRTV(Device * OwnerDevice)
{
	// Device version 3 required to create a RTV1
	if(Version == 0 || OwnerDevice->GetDeviceVersion() < 3)
	{
		D3D11_RENDER_TARGET_VIEW_DESC rtv_desc;
		rtv_desc.Format = Desc.Format;

		if(Desc.ArrayCount > 0)
		{
			rtv_desc.Texture2D.MipSlice = 0;
			rtv_desc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
		}
		else
		{
			rtv_desc.Texture2DArray..MipSlice = 0;
			rtv_desc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
		}

		LogCheckWithReturn(OwnerDevice->GetDevice()->CreateRenderTargetView(TextureResource,&rtv_desc,&RTV),LogCategory::Error);
	}
	else if(Version == 1)
	{
		D3D11_RENDER_TARGET_VIEW_DESC1 rtv_desc;
		rtv_desc.Format = desc.Format;
		rtv_desc.Texture2D.MipSlice = 0;
		rtv_desc.Texture2D.PlaneSlice = 0;
		rtv_desc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;

		LogCheckWithReturn(OwnerDevice->GetDevice3()->CreateRenderTargetView1(TextureResource,&rtv_desc,(ID3D11RenderTargetView1**)&RTV),LogCategory::Error);
	}
	else
		return StatusCode::InvalidArgument;
	return StatusCode::Ok;
}

StatusCode FrameDX::Texture2D::CreateFromSwapChain(Device * OwnerDevice)
{
	// Check swapchain version
	if(OwnerDevice->GetSwapChainVersion() == 1)
	{
		Version = 1;
		LogCheckWithReturn(OwnerDevice->GetSwapChain1(false)->GetBuffer(0, __uuidof(ID3D11Texture2D1), (void**)&TextureResource),LogCategory::Error);
	}
	else
	{
		Version = 0;
		LogCheckWithReturn(OwnerDevice->GetSwapChain()->GetBuffer(0, __uuidof(ID3D11Texture2D1), (void**)&TextureResource),LogCategory::Error);
	}
	
	// Get description
	D3D11_TEXTURE2D_DESC desc;
	TextureResource->GetDesc(&desc);

	Desc.SizeX = desc.Width;
	Desc.SizeY = desc.Height;
	Desc.Format = desc.Format;
	Desc.BindFlags = desc.BindFlags;
	Desc.Usage = desc.Usage;
	Desc.AccessFlags = desc.CPUAccessFlags;

	// Check if an UAV or SRV needs to be created
	if(desc.BindFlags & D3D11_BIND_SHADER_RESOURCE)
		LogCheckWithReturn(CreateSimpleSRV(OwnerDevice),LogCategory::Error);
	if(desc.BindFlags & D3D11_BIND_UNORDERED_ACCESS)
		LogCheckWithReturn(CreateSimpleUAV(OwnerDevice),LogCategory::Error)
	if(desc.BindFlags & D3D11_BIND_RENDER_TARGET)
		LogCheckWithReturn(CreateSimpleRTV(OwnerDevice),LogCategory::Error)

	return StatusCode::Ok;
}

StatusCode FrameDX::Texture2D::CreateFromDescription(Device * OwnerDevice, const Texture::Description & Desc)
{
	if(OwnerDevice->GetDeviceVersion() >= 3)
	{
		D3D11_TEXTURE2D_DESC1 desc;
		desc.

	}
	else
	{

	}

	return StatusCode::Ok;
}
