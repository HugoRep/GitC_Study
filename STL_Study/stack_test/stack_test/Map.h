#pragma once
#include <iostream>
#include<iomanip>

const int MapWidth = 10;
const int MapHeight = 10;

using namespace std;

class Map
{

public:
	Map();
	~Map();

	void Init();

	void Draw();

	void DirectionCheck(int CurrentValue);

	void MapCheck();
	

	const int Data[MapHeight][MapWidth] = {
		{ 0, 0, 1,1, 1, 1 ,1, 1, 1, 1 },
		{ 1, 0, 0,1, 1, 1 ,1, 1, 1, 1 },
		{ 1, 1, 0,0, 0, 0 ,0, 1, 1, 1 },
		{ 1, 1, 1,1, 0, 1 ,0, 1, 1, 1 },
		{ 1, 1, 1,1, 0, 1 ,0, 1, 1, 1 },
		{ 1, 1, 1,1, 0, 1 ,0, 1, 1, 1 },
		{ 1, 1, 1,1, 0, 1 ,0, 0, 1, 1 },
		{ 1, 1, 1,1, 0, 1 ,1, 0, 0, 1 },
		{ 1, 1, 1,1, 0, 0 ,0, 0, 0, 1 },
		{ 1, 1, 1,1, 0, 1 ,1, 1, 0, 2 },
	};

	void mapCheck();
	

};

