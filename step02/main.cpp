#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


#define UP 75
#define DOWN 77
#define LEFT 72
#define RIGHT 80
#define size 10;

bool bIsRunning = true;

//int main()
//{
	/*int a = 0;
	int b = 1;

	scanf_s("%d", &a);
	scanf_s("%d", &b);

	printf("%d", a + b);*/

	/*int a[size];
	int sum = 0;

	int *b = (int*)malloc(10);

	for (int i=0; i < 10; i++){
		sum += a[i];
	}*/

	//int size = 5;
	//int sum = 0;
	//int i = 0;
	//int* pNumber = (int*)malloc(sizeof(int) *size);
	//
	//scanf_s("%d", pNumber);
	//for (i = 0; i < size; i++)
	//{
	//	scanf("%d", &pNumber[i]);
	//}
	//
	//for (i = 0; i < size; i++)
	//{
	//	sum += pNumber[i];
	//}
	//printf("%d \n", sum);
	//free(pNumber);

	/*int i, n;
	char * buffer;
	scanf("%d", &i);

	buffer = (char*)malloc(i + 1);
	if (buffer == NULL) exit(1);

	for (n = 0; n < i; n++)
		buffer[n] = rand() % 26 + 'a';
	buffer[i] = '\0';

	printf("Random string: %s\n", buffer);

	free(buffer);*/
/*
	char c2[6];
	char c[6] = "hello";

	int i = 0;

	while (i < 5)
	{
		printf("*\n");
		i++;
	}	

	return 0;*/


//}

int currentX = 1; 
int currentY = 1;

int map[10][10] = { {1,1,1,1,1,1,1,1,1,1},
					{1,0,0,1,0,0,0,0,0,1},
					{1,0,0,1,0,0,0,0,0,1},
					{1,0,0,1,0,0,0,0,0,1},
					{1,0,0,1,0,0,0,0,0,1},
					{1,0,0,0,0,0,1,0,0,1},
					{1,0,0,0,0,0,1,0,0,1},
					{1,0,0,0,0,0,1,0,0,1},
					{1,0,0,0,0,0,1,0,0,1},
					{1,1,1,1,1,1,1,1,1,1},
};

int Input()
{
	int keyCode = getch();
	return keyCode;
}

void Tick(int keyCode)
{
	//map check
	int mapCheck = map[currentY][currentX];


	if (currentX < 0)currentX = 0;
	else if (currentX > 10) currentX = 10;
	else if (currentY < 0)currentY = 0;
	else if (currentY > 10) currentY = 10;

	if (currentX < 0 || currentX > 10 || currentY < 0 || currentY > 10)return;

	switch (keyCode)
	{
	case  UP:
		currentX--;
		break;
	case DOWN:
		currentX++;
		break;
	case LEFT:
		currentY--;
		break;
	case RIGHT:
		currentY++;
		break;
	case 'Q':
	case 'q':
		bIsRunning = false;
		break;
	}
}

void Draw()
{
	system("cls");
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			if (x == currentX && y == currentY)
			{
				printf("@");
			}
			else
			{
				printf("%d", map[y][x]);
			}
		}
		printf("\n");
	}
}


int main()
{
	while (bIsRunning)
	{
		int KeyCode = Input();
		Tick(KeyCode);
		Draw();
	}
}