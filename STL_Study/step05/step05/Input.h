#pragma once
#include <stdio.h>
#include <strstream>
#include <conio.h>

class Input
{
public:
	const static int LEFT = 75;		// 좌측방향키 
	const static int RIGHT = 77;      // 우측방향키 
	const static int UP = 72;			// 위쪽방향키 
	const static int DOWN = 80;       // 아래방향키

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

