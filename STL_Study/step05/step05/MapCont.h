#pragma once

#ifndef __MAPCONT_H__
#define __MAPCONT_H__

#include <stdio.h>
#include <strstream>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include "Util.h"
#include "defaultConst.h"

using namespace std;
const int MapWidth = 10, MapHeight = 10;




class MapCont
{
public:
	static MapCont* GetInstance()
	{
		if (instance == nullptr) instance = new MapCont();
		return instance;
	}
	void Init();

	void Tick();
	void Render();
	void Draw();
	void MakeMap();

	char GetMapTile(defaultConst Type);
	
private:
	MapCont() {}
	~MapCont() {}

	static MapCont* instance;


	

	char Data[MapHeight][MapWidth] = {
		{ '1', '1', '0', '1', '1', '1', '1', '1', '1', '1' },
		{ '1', '1', '1', '1', '1', '1', '1', '1', '1', '1' },
		{ '1', '1', '0', '1', '1', '1', '1', '1', '0', '0' },
		{ '1', '1', '0', '0', '1', '1', '1', '1', '0', '1' },
		{ '1', '1', '1', '1', '1', '1', '1', '1', '1', '1' },
		{ '0', '0', '0', '1', '0', '0', '1', '0', '0', '1' },
		{ '1', '1', '1', '1', '1', '0', '0', '0', '1', '1' },
		{ '1', '1', '1', '0', '0', '0', '1', '1', '1', '1' },
		{ '1', '1', '0', '0', '0', '0', '0', '1', '1', '0' },
		{ '1', '1', '1', '0', '0', '1', '1', '1', '1', '3' }
	};
};
#endif
