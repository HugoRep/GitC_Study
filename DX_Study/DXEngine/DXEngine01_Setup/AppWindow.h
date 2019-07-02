#pragma once
#include <Windows.h>

//���漱��
class Engine;

class AppWindow
{
public:
	AppWindow(HINSTANCE hinstance);
	~AppWindow();

	int Run(Engine* engine);
	bool InitializeWindow();

	virtual LRESULT MessageProcessor(
		HWND hwnd,
		UINT msg,
		WPARAM wParam,
		LPARAM lParam
	);

protected:
	HWND hwnd;					//������ �ڵ�
	HINSTANCE hinstance;		//â �ν��Ͻ�
	UINT screeWidth;			//ȭ�� ����ũ��
	UINT screeHeight;			//ȭ�� ����ũ��
	LPCTSTR applicationName;	//â �̸�
	DWORD windowStyle;			//â ���
};

