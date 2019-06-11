#include "Engine.h";

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
	/*for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			if (x == PlayerX && y == PlayerY)
			{
				printf("@");
			}
			else
			{
				printf("%d", Map[y][x]);
			}
		}
		printf("\n");
	}*/
}

int Engine::Input()
{
	int keyCode = getch();
	return keyCode;
}

void Engine::Tick(int keyCode)
{
	/*switch (keyCode)
	{
	case  UP:
		PlayerX--;
		break;
	case DOWN:
		PlayerX++;
		break;
	case LEFT:
		PlayerY--;
		break;
	case RIGHT:
		PlayerY++;
		break;
	case 'Q':
	case 'q':
		bIsRunning = false;
		break;
	}

	PlayerX = Clamp(PlayerX, 1, 8);
	PlayerY = Clamp(PlayerY, 1, 8);*/
}
