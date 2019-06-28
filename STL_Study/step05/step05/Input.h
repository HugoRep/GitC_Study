#pragma once
#include <stdio.h>
#include <strstream>
#include <conio.h>

class Input
{
public:
	const static int LEFT = 75;		// ��������Ű 
	const static int RIGHT = 77;      // ��������Ű 
	const static int UP = 72;			// ���ʹ���Ű 
	const static int DOWN = 80;       // �Ʒ�����Ű

	static Input* GetInstance()
	{
		if (instance == nullptr) instance = new Input();
		return instance;
	}

	int keyCode;

	void getKeyInput();

	void Init();

	void Tick();

	void Draw();

	void Render();

private:
	Input();
	virtual ~Input();
	static Input* instance;
};

