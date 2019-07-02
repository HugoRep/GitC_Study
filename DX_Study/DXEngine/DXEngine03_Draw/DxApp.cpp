#include "DxApp.h"

DxApp::DxApp()
{
}

DxApp::DxApp(HINSTANCE hinstance)
{
	window = new AppWindow(hinstance);
}

DxApp::~DxApp()
{
	//delete window;
	Memory::SafeDelete(window);

	
	//DX 리소스 해제
	Memory::SafeRelease(device);
	Memory::SafeRelease(deviceContext);
	Memory::SafeRelease(swapChain);
	Memory::SafeRelease(renderTargetView);
}

bool DxApp::Init()
{
	//창 초기화
	
	if (window->InitializeWindow() == false)
		return false;

	//DX 초기화
	if (InitializeDirect3D() == false)
		return false;

	return true;
}

bool DxApp::InitializeDirect3D()
{
	//스왑체인 생성 - Back/Front 버퍼 교환용.
	//서술자(Descripor).
	DXGI_SWAP_CHAIN_DESC swapDesc;

	/*
	DXGI_MODE_DESC   BufferDesc;
	DXGI_SAMPLE_DESC SampleDesc;
	DXGI_USAGE       BufferUsage;
	UINT             BufferCount;
	HWND             OutputWindow;
	BOOL             Windowed;
	DXGI_SWAP_EFFECT SwapEffect;
	UINT             Flags;
	*/

	ZeroMemory(&swapDesc, sizeof(DXGI_SWAP_CHAIN_DESC));

	swapDesc.BufferCount = 1;		//
	swapDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapDesc.OutputWindow = window->GEtWindowHandler();
	swapDesc.Windowed = true;		//windowMode;
	swapDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	swapDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapDesc.BufferDesc.Width = window->GetScreenWidth();
	swapDesc.BufferDesc.Height = window->GetScreenHeight();

	swapDesc.SampleDesc.Count = 1;				//안티 알리아싱관련
	swapDesc.SampleDesc.Quality = 0;

	//스왑체인 장치 생성
	HRESULT result= D3D11CreateDeviceAndSwapChain(NULL,
		D3D_DRIVER_TYPE_HARDWARE,
		NULL,
		NULL,
		NULL,
		NULL,
		D3D11_SDK_VERSION,
		&swapDesc,
		&swapChain,
		&device,
		NULL,
		&deviceContext);

	 //오류 확인
	 if (FAILED(result))
	 {
		 MessageBox(NULL, TEXT("장치 생성 실패"), TEXT("오류"), MB_OK);
		 return false;
	 }

	 //백버퍼(텍스처 ) 생성
	ID3D11Texture2D* backBufferTexture = NULL;
	result = swapChain->GetBuffer(NULL, __uuidof(ID3D11Texture2D), (LPVOID*)&backBufferTexture);

	if (FAILED(result))
	{
		MessageBox(NULL, TEXT("백버퍼 생성 실패"), TEXT("오류"), MB_OK);
		return false;
	}

	//랜더 타겟 뷰 생성
	result = device->CreateRenderTargetView(backBufferTexture, NULL , &renderTargetView);
	if (FAILED(result))
	{
		MessageBox(NULL, TEXT("랜더 타겟 실패"), TEXT("오류"), MB_OK);
		return false;
	}
	deviceContext->OMSetRenderTargets(1, &renderTargetView, NULL);
	//버퍼 생성을 위한 자원 해제
	Memory::SafeRelease(backBufferTexture);

	//뷰포트 설정
	SetViewport();

	return true;
}

void DxApp::SetViewport()
{
	D3D11_VIEWPORT viewport;
	ZeroMemory(&viewport, sizeof(D3D11_VIEWPORT));

	//뷰포트 좌표 0~1;
	viewport.TopLeftX = 0;
	viewport.TopLeftY = 0;
	viewport.Width = static_cast<float>(window->GetScreenWidth());
	viewport.Height = static_cast<float>(window->GetScreenHeight());
}
