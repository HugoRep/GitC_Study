#include "Engine.h"
#include "Player.h"
#include "Map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void Engine::init(Player * _player, Map * _map)
{
	map = _map;
	map->init(_player);
}

void Engine::Run()
{
	while (bIsRunning)
	{
		int KeyCode = Input();
		Tick(KeyCode);
		Draw();
	}
}

void Engine::Draw()
{
	system("cls");
	map->Draw();
	
	
}

int Engine::Input()
{
	int keyCode = getch();
	return keyCode;
}

void Engine::Tick(int keyCode)
{
	map->Tick(keyCode);

	switch (keyCode)
	{
	case 'Q':
	case 'q':
		bIsRunning = false;
		break;
	}
	
}

void Engine::Setting(int argc, char ** argv)
{
	printf("%d", argv[0], argv[0]);
}
