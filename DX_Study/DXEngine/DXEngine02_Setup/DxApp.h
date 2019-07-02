#pragma once
#include "AppWindow.h"
#include "DXUtil.h"

class DxApp
{
public:
	DxApp();
	DxApp(HINSTANCE hinstance);
	virtual ~DxApp();

	virtual int Run() = 0;
	virtual bool Init();
	virtual void Update() = 0;
	virtual void Render() = 0;
	
protected:

	AppWindow* window;

	ID3D11Device* device;				//
	ID3D11DeviceContext* deviceContext;	//

	IDXGISwapChain* swapChain;
	ID3D11RenderTargetView* renderTargetView;

protected:
	bool InitializeDirect3D();
	
};

