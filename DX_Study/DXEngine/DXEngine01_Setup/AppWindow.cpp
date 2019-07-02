#include "AppWindow.h"
#include "Engine.h"
#include <iostream>

AppWindow* app = NULL;

//������ �޼��� ���ν��� ( �޼��� ó����);
LRESULT CALLBACK WindowProcessor(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	if (app != NULL)
		return app->MessageProcessor(hwnd, msg, wParam, lParam);
	else
		return DefWindowProc(hwnd, msg, wParam, lParam);
}

AppWindow::AppWindow(HINSTANCE hinstance)
{
	hwnd = NULL;
	this->hinstance = hinstance;
	screeWidth = 1600;
	screeHeight = 900;
	applicationName = TEXT("Engine00 - Window Setup");
	windowStyle = WS_OVERLAPPEDWINDOW;
	app = this;
}


AppWindow::~AppWindow()
{

}

int AppWindow::Run(Engine * engine)
{
	MSG msg;								//�޽��� ����
	ZeroMemory(&msg, sizeof(MSG));			//�޸� �ʱ�ȭ

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0,PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			engine->Update();
			engine->Render();
		}
	}
	return 0;
}

bool AppWindow::InitializeWindow()
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	//â ����ü �� ����.
	
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = hinstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = NULL;
	wc.lpszClassName = TEXT("DXEngine");
	wc.lpfnWndProc = WindowProcessor;


	if (!RegisterClassEx(&wc))
	{
		return false;
	}
	//â �ڵ� �����
	hwnd = CreateWindow(wc.lpszClassName, applicationName, windowStyle, 0, 0, screeWidth, screeHeight, NULL, NULL, hinstance, NULL);

	if (hwnd == NULL)
	{
		return false;
	}
	ShowWindow(hwnd, SW_SHOW);
	return true;
}

LRESULT AppWindow::MessageProcessor(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		case WM_KEYDOWN :
		{
			if (wParam == VK_ESCAPE)
			{
				if (MessageBox(NULL,
					TEXT("���� �Ͻðڽ��ϱ�?"),
					TEXT("����"), MB_YESNO | MB_ICONQUESTION) == IDYES)
				{
					//�� ��ư ������ â ����
					DestroyWindow(this->hwnd);
				}
			}
			break;
		}
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}		
	}
	return DefWindowProc(hwnd, msg , wParam , lParam);
}