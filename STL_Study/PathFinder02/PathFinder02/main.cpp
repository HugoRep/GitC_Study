#include <iostream>
#include <stack>
#include <queue>
#include <conio.h>

using namespace std;

#define MAX 10
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



int maze[MAX][MAX] =
{
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
	{1, 1, 1, 1, 0, 0, 0, 0, 1, 1},
	{1, 1, 1, 1, 0, 1, 1, 0, 1, 1},
	{1, 1, 1, 1, 0, 1, 1, 0, 1, 1},
	{1, 1, 1, 1, 0, 1, 1, 0, 1, 1},
	{1, 1, 0, 0, 0, 1, 1, 0, 1, 1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
};

//현재위치에서 일정한 방법으로 미리 이동 해보고 
//이동 가능한지 알려줌
bool CanMove(Vector2& Current)
{
	Vector2 Next;

	//4방향 움직이기
	for (int dir = (int)Direction::Right; dir <= (int)Direction::Up; ++dir)
	{
		Next = Current; // 다음에 갈곳
		Next = Next + Dir[dir]; //방향 이동. Right->Down->Left->Up
		if (Next.x < 0 || Next.y < 0 || Next.x >= MAX || Next.y >= MAX) //이동 할곳이 정확한지
		{
			continue;//현재 방향 다음 방향 이동
		}

		if (maze[Next.y][Next.x] == WAY) //미리 가보는곳이 갈수 있는지?
		{
			Current = Next;
			return true;
		}
	}

	return false; //다음 갈곳이 없음
}

#define LEVEL			100

bool CanMoveQ(Vector2& NewPosition)
{
	if (NewPosition.x < 0 || NewPosition.y < 0 ||
		NewPosition.x >= MAX || NewPosition.y >= MAX)
	{
		return false;
	}

	if (maze[NewPosition.y][NewPosition.x] == WAY) //갈수 있으므로 큐에 넣고 레벨 저장
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

	if (maze[NewPosition.y][NewPosition.x] == Level) //갈수 있으므로 큐에 넣고 레벨 저장
	{
		return true;
	}

	return false;
}

int main()
{
	queue<Vector2> Q;
	Vector2 Current;

	Q.push(Current);
	maze[Current.y][Current.x] = LEVEL;
	bool found = false;

	while (!Q.empty())
	{
		Current = Q.front();
		Q.pop();

		int CurrentLevel = maze[Current.y][Current.x];

		for (int dir = (int)Direction::Right; dir <= (int)Direction::Up; ++dir)
		{
			Vector2 NewPosition;
			NewPosition = Current + Vector2(deltas[dir]); //Right
			if (CanMoveQ(NewPosition))
			{
				maze[NewPosition.y][NewPosition.x] = CurrentLevel + 1;
				Q.push(NewPosition);
			}
		}


		if (Current.x == (MAX - 1) && Current.y == (MAX - 1)) //탈출
		{
			cout << "탈출" << endl;
			found = true;
			break;
		}
	}

	if (found == false)
	{
		cout << "탈출불가" << endl;
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
		

		int MaxLevel = maze[TracePosition.y][TracePosition.x];

		if (TracePosition.x == 0 && TracePosition.y == 0)
		{
			maze_escape[TracePosition.y][TracePosition.x] = 0;
			break;
		}
		

		for (int dir = (int)Direction::Right; dir <= (int)Direction::Up; ++dir)
		{
			
			cout <<  "check : "<< deltas[dir].x  << " ," << deltas[dir].y << endl;
		}

		Vector2 Next;

		Next = TracePosition + Vector2(1, 0);
		if (TraceMoveQ(Next, MaxLevel - 1))
		{
			TracePosition = Next;
			maze_escape[Next.y][Next.x] = 0;
			continue;
		}

		Next = TracePosition + Vector2(0, 1);
		if (TraceMoveQ(Next, MaxLevel - 1))
		{
			TracePosition = Next;
			maze_escape[Next.y][Next.x] = 0;
			continue;
		}

		Next = TracePosition + Vector2(-1, 0);
		if (TraceMoveQ(Next, MaxLevel - 1))
		{
			TracePosition = Next;
			maze_escape[Next.y][Next.x] = 0;
			continue;
		}

		Next = TracePosition + Vector2(0, -1);
		if (TraceMoveQ(Next, MaxLevel - 1))
		{
			TracePosition = Next;
			maze_escape[Next.y][Next.x] = 0;
			continue;
		}
	}


	for (int y = 0; y < MAX; ++y)
	{
		for (int x = 0; x < MAX; ++x)
		{
			cout << maze_escape[y][x] << "  ";
		}
		cout << endl;
	}


	return 0;
}