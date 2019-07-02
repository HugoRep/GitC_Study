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

	
	//DX ���ҽ� ����
	Memory::SafeRelease(device);
	Memory::SafeRelease(deviceContext);
	Memory::SafeRelease(swapChain);
	Memory::SafeRelease(renderTargetView);
}

bool DxApp::Init()
{
	//â �ʱ�ȭ
	
	if (window->InitializeWindow() == false)
		return false;

	//DX �ʱ�ȭ
	if (InitializeDirect3D() == false)
		return false;

	return true;
}

bool DxApp::InitializeDirect3D()
{
	//����ü�� ���� - Back/Front ���� ��ȯ��.
	//������(Descripor).
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

	swapDesc.SampleDesc.Count = 1;				//��Ƽ �˸��ƽ̰���
	swapDesc.SampleDesc.Quality = 0;

	//����ü�� ��ġ ����
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

	 //���� Ȯ��
	 if (FAILED(result))
	 {
		 MessageBox(NULL, TEXT("��ġ ���� ����"), TEXT("����"), MB_OK);
		 return false;
	 }

	 //�����(�ؽ�ó ) ����
	ID3D11Texture2D* backBufferTexture = NULL;
	result = swapChain->GetBuffer(NULL, __uuidof(ID3D11Texture2D), (LPVOID*)&backBufferTexture);

	if (FAILED(result))
	{
		MessageBox(NULL, TEXT("����� ���� ����"), TEXT("����"), MB_OK);
		return false;
	}

	//���� Ÿ�� �� ����
	result = device->CreateRenderTargetView(backBufferTexture, NULL , &renderTargetView);
	if (FAILED(result))
	{
		MessageBox(NULL, TEXT("���� Ÿ�� ����"), TEXT("����"), MB_OK);
		return false;
	}
	deviceContext->OMSetRenderTargets(1, &renderTargetView, NULL);
	//���� ������ ���� �ڿ� ����
	Memory::SafeRelease(backBufferTexture);

	//����Ʈ ����
	SetViewport();

	return true;
}

void DxApp::SetViewport()
{
	D3D11_VIEWPORT viewport;
	ZeroMemory(&viewport, sizeof(D3D11_VIEWPORT));

	//����Ʈ ��ǥ 0~1;
	viewport.TopLeftX = 0;
	viewport.TopLeftY = 0;
	viewport.Width = static_cast<float>(window->GetScreenWidth());
	viewport.Height = static_cast<float>(window->GetScreenHeight());
}
