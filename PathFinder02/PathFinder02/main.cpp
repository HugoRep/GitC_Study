#include <iostream>
#include <stack>
#include <queue>
#include <conio.h>

using namespace std;

#define MAX 5
#define WAY 0
#define WALL 1
#define BLOCK 2
#define PATH 3

class Vector2
{
public:
	Vector2() : x(0), y(0) {}
	Vector2(int _x, int _y) : x(_x), y(_y) {}
	int x;
	int y;

	Vector2 operator+(const Vector2& RightHandSide)
	{
		Vector2 Result;
		Result.x = this->x + RightHandSide.x;
		Result.y = this->y + RightHandSide.y;

		return Result;
	}
};

enum class Direction
{
	Right = 0,
	Down = 1,
	Left = 2,
	Up = 3
};

Vector2 Dir[4];
Vector2 deltas[4] = { {1,0}, {0,1}, {0,+1}, {-1,0} };



int Maze[MAX][MAX] = {
 {0, 1, 1, 1, 0},
 {0, 0, 0, 0, 0},
 {1, 0, 1, 1, 1},
 {1, 0, 1, 1, 1},
 {1, 0, 0, 0, 0}
};

//������ġ���� ������ ������� �̸� �̵� �غ��� 
//�̵� �������� �˷���
bool CanMove(Vector2& Current)
{
	Vector2 Next;

	//4���� �����̱�
	for (int dir = (int)Direction::Right; dir <= (int)Direction::Up; ++dir)
	{
		Next = Current; // ������ ����
		Next = Next + Dir[dir]; //���� �̵�. Right->Down->Left->Up
		if (Next.x < 0 || Next.y < 0 || Next.x >= MAX || Next.y >= MAX) //�̵� �Ұ��� ��Ȯ����
		{
			continue;//���� ���� ���� ���� �̵�
		}

		if (Maze[Next.y][Next.x] == WAY) //�̸� �����°��� ���� �ִ���?
		{
			Current = Next;
			return true;
		}
	}

	return false; //���� ������ ����
}

#define LEVEL			100

bool CanMoveQ(Vector2& NewPosition)
{
	if (NewPosition.x < 0 || NewPosition.y < 0 ||
		NewPosition.x >= MAX || NewPosition.y >= MAX)
	{
		return false;
	}

	if (Maze[NewPosition.y][NewPosition.x] == WAY) //���� �����Ƿ� ť�� �ְ� ���� ����
	{
		return true;
	}

	return false;
}


bool TraceMoveQ(Vector2& NewPosition, int Level)
{
	if (NewPosition.x < 0 || NewPosition.y < 0 ||
		NewPosition.x >= MAX || NewPosition.y >= MAX)
	{
		return false;
	}

	if (Maze[NewPosition.y][NewPosition.x] == Level) //���� �����Ƿ� ť�� �ְ� ���� ����
	{
		return true;
	}

	return false;
}

/*
(0, 0)
(0, 1)
(1, 1)
(1, 2)
(1, 3)
(1, 4)
(2, 4)
(3, 4)
(4, 4)*/

int main()
{
	queue<Vector2> Q;
	Vector2 Current;

	Q.push(Current);
	Maze[Current.y][Current.x] = LEVEL;
	bool found = false;

	while (!Q.empty())
	{
		Current = Q.front();
		Q.pop();

		int CurrentLevel = Maze[Current.y][Current.x];

		for (int dir = (int)Direction::Right; dir <= (int)Direction::Up; ++dir)
		{
			Vector2 NewPosition;
			NewPosition = Current + Vector2(deltas[dir]); //Right
			if (CanMoveQ(NewPosition))
			{
				Maze[NewPosition.y][NewPosition.x] = CurrentLevel + 1;
				//cout << "check : " << Current.x << " , " << Current.y << endl;
				Q.push(NewPosition);
			}
		}


		if (Current.x == (MAX - 1) && Current.y == (MAX - 1)) //Ż��
		{
			cout << "map : " << Current.x << " , " << Current.y<< endl;
			found = true;
			break;
		}
		
		
		
	}

	if (found == false)
	{
		cout << "Ż��Ұ�" << endl;
	}

	int maze_escape[MAX][MAX] = {
		{1,}
	};

	for (int y = 0; y < MAX; ++y)
	{
		for (int x = 0; x < MAX; ++x)
		{
			maze_escape[y][x] = 1;
		}
	}


	Vector2 TracePosition(MAX - 1, MAX - 1);
	maze_escape[TracePosition.y][TracePosition.x] = 0;
	while (true)
	{
		int MaxLevel = Maze[TracePosition.y][TracePosition.x];
		if (TracePosition.x == 0 && TracePosition.y == 0)
		{
			maze_escape[TracePosition.y][TracePosition.x] = 0;
			break;
		}
		
		/*
		for (int dir = (int)Direction::Right; dir <= (int)Direction::Up; ++dir)
		{
			cout << TracePosition.x << ","<<  TracePosition.y << endl;
		}*/

		Vector2 Next;

		Next = TracePosition + Vector2(1, 0);
		if (TraceMoveQ(Next, MaxLevel - 1))
		{
			TracePosition = Next;
			maze_escape[Next.y][Next.x] = 0;
			cout << "map : " << Next.x << " , " << Next.y << endl;
			continue;
		}

		Next = TracePosition + Vector2(0, 1);
		if (TraceMoveQ(Next, MaxLevel - 1))
		{
			TracePosition = Next;
			maze_escape[Next.y][Next.x] = 0;
			cout << "map : " << Next.x << " , " << Next.y << endl;
			continue;
		}

		Next = TracePosition + Vector2(-1, 0);
		if (TraceMoveQ(Next, MaxLevel - 1))
		{
			TracePosition = Next;
			maze_escape[Next.y][Next.x] = 0;
			cout << "map : " << Next.x << " , " << Next.y << endl;
			continue;
		}

		Next = TracePosition + Vector2(0, -1);
		if (TraceMoveQ(Next, MaxLevel - 1))
		{
			TracePosition = Next;
			maze_escape[Next.y][Next.x] = 0;
			cout << "map : " << Next.x << " , " << Next.y << endl;
			continue;
		}
	}


	return 0;
}