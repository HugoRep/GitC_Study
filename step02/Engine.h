#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

class Engine
{
public:
	void Run();
	void Draw();
	void Tick(int keyCode);
	int Input();

	bool bIsRunning = true;

};