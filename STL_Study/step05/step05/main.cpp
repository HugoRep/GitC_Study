#include <stdio.h>
#include <bitset>
#include <iostream>

using namespace std;

const int MapWidth = 10, MapHeight = 10;

const char FLOOR = '1';
const char WALL = '0';
const char GOAL = 'G';


char Map[MapHeight][MapWidth] = {
		{ '1', '1', '0', '1', '1', '1', '1', '1', '1', '1' },
		{ '1', '1', '1', '1', '1', '1', '1', '1', '1', '1' },
		{ '1', '1', '0', '1', '1', '1', '1', '1', '0', '0' },
		{ '1', '1', '0', '0', '1', '1', '1', '1', '0', '1' },
		{ '1', '1', '1', '1', '1', '1', '1', '1', '1', '1' },
		{ '0', '0', '0', '1', '0', '0', '1', '0', '0', '1' },
		{ '1', '1', '1', '1', '1', '0', '0', '0', '1', '1' },
		{ '1', '1', '1', '0', '0', '0', '1', '1', '1', '1' },
		{ '1', '1', '0', '0', '0', '0', '0', '1', '1', '0' },
		{ '1', '1', '1', '0', '0', '1', '1', '1', '1', 'G' },
};

//
//struct SearchMapItem
//{
//	bool traversble;
//	bool goal;
//	bool visited;
//	/*int cost_here;
//	Dir came_from;
//	bool paths[d_end];*/
//};



struct Pos
{
	short x, y;
	Pos(short x = 0, short y = 0) : x(x), y(y) {}
};

char replaceValue(char type)
{
	switch (type)
	{
	case '1':
		return '@';
		break;
	}
}

int main() {
	
	//Engine *engine = new Engine();
	//engine->Input();

	//MapCont *s = s->GetInstance();
	//s->GetInstance()->Init();
	//s->GetInstance()->Draw();

	//Input* input = input->GetInstance();
	//input->GetInstance()->getKeyInput();

	

	//for (int y = 0; y < 10; ++y)
	//{
	//	for (int x = 0; x < 10; ++x)
	//	{
	//		
	//		char dataValue = Data[y][x];
	//		Data[y][x] = replaceValue(dataValue);
	//		cout << Data[y][x];
	//	}
	//	cout << endl;
	//}


	
	Pos p;
	for (p.y = 0; p.y < MapHeight; ++p.y)
	{
		for (p.x = 0; p.x < MapWidth; ++p.x)
		{
			//SearchMapItem smi;
			//smi.visited = false;

			if (Map[p.y][p.x] == WALL)
			{
				//cout << "Wall" << endl;
				Map[p.y][p.x] = '9';
			}
			else if (Map[p.y][p.x] == GOAL)
			{
				
			}
			else if (Map[p.y][p.x] == FLOOR)
			{
				Map[p.y][p.x] = '0';
			}


			char *dataValue = (char*)Map[p.y][p.x];
			//Map[p.y][p.x] = replaceValue(dataValue);
			//search_map[p] = smi;
			cout << Map[p.y][p.x];
			
			
			
		}
		
		cout << endl;
	}
	
	return 0;
}