#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

class Engine
{
public:
	void init(class Player* _player, class Map* _map);
	void Run();
	void Draw();
	void Tick(int keyCode);

	void Setting(int argc, char **argv);



	int Input();

	bool bIsRunning = true;

	class Map* map;
};