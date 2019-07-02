#include "Engine.h"


Engine::Engine(HINSTANCE hinstance)
	: DxApp(hinstance)
{
	
}

Engine::~Engine()
{
}

int Engine::Run()
{
	return window -> Run(this);
}

bool Engine::Init()
{
	if (DxApp::Init() == false)
		return false;
	
	return true;
}

void Engine::Update()
{
}

void Engine::Render()
{
	float color[]{ 0.0f, 0.5f, 0.5f, 1.0f };

	//���� Ÿ���� ������ �������� ĥ�ϱ�
	deviceContext->ClearRenderTargetView(renderTargetView, color);

	//����� <->����Ʈ ���� ��ȯ.
	swapChain->Present(1, 0);
}
