#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

const char FLOOR = 0;
const char WALL = 1;
const char GOAL = 2;

const int MapWidth = 10, MapHeight = 10;
int Map[MapHeight][MapWidth] = {
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

struct Pos
{
	short x, y;
	Pos operator + (Pos p) const { return Pos(x + p.x, y + p.y); }
	bool operator < (Pos p) const { return (y == p.y) ? (x < p.x) : (y < p.y); }
	bool operator != (Pos p) const { return (y != p.y) || (x != p.x); }
	Pos(short x = 0, short y = 0) : x(x), y(y) {}
};

//¸Ê Ã¼Å©
bool MapCheck (Pos p) 
{
	return p.x >= 0 && p.x < MapWidth && p.y >= 0 && p.y < MapHeight; 
}

enum Dir { d_beg, d_up = d_beg, d_rg, d_dn, d_lf, d_end };

Pos deltas[d_end] = { {0,-1}, {+1,0}, {0,+1}, {-1,0} };

Dir& operator ++ (Dir& d) { d = (Dir)(1 + (int)d); return d; }

Dir other(Dir d)
{
	switch (d)
	{
	case d_up: return d_dn;
	case d_rg: return d_lf;
	case d_dn: return d_up;
	case d_lf: return d_rg;
	default: return d_end;
	}
}

struct SearchMapItem
{
	bool traversble;
	bool goal;
	bool visited;
	int cost_here;
	Dir came_from;
	bool paths[d_end];
};

map<Pos, SearchMapItem> search_map;
typedef map<Pos, SearchMapItem>::iterator SMII;

void MakeMap()
{
	search_map.clear();
	Pos p;
	for (p.y = 0; p.y < MapHeight; ++p.y) 
	{
		for (p.x = 0; p.x < MapWidth; ++p.x)
		{
			SearchMapItem smi;
			smi.visited = false;
			smi.cost_here = -1;
			smi.came_from = d_end;

			if (Map[p.y][p.x] == WALL)
			{
				smi.traversble = false;
			}
			else if (Map[p.y][p.x] == GOAL)
			{
				smi.traversble = true;
				smi.goal = true;
			}
			else if (Map[p.y][p.x] == FLOOR)
			{
				smi.traversble = true;
				smi.goal = false;
				for (Dir d = d_beg; d != d_end; ++d)
				{
					Pos p2 = p + deltas[d];
					
					Map[p.y][p.x] = 3;
					smi.paths[d] = MapCheck(p2) && (Map[p2.y][p2.x] != WALL);
				}
			}
			search_map[p] = smi;
		}
	}
}

void FindGoalFrom(Pos start)
{
	vector<SMII> found;
	{
		SMII smii = search_map.find(start);

		if (smii == search_map.end()) { cout << "map " << endl; return; }
		if (smii->second.goal) { cout << "goal " << endl; return; }
		if (!smii->second.traversble) { cout << "starting" << endl; return; }

		smii->second.visited = true;
		smii->second.cost_here = 0;
		found.push_back(smii);
	}

	int cost_so_far = 0;
	bool finde_check = false;

	while (!finde_check)
	{
		vector<SMII> candidates;
		for (SMII smii : found)
		{
			for (Dir d = d_beg; d != d_end; ++d)
			{
				if (!smii->second.paths[d]) continue;
				Pos p = smii->first + deltas[d];


				if (!MapCheck(p)) continue;

				SMII cand = search_map.find(p);

				if (cand == search_map.end()) continue;
				if (cand->second.visited) continue;
				cand->second.came_from = d;
				candidates.push_back(cand);

				Map[p.y][p.x] = cost_so_far;
				
			}
		}

		++cost_so_far;
		if (candidates.empty()) break;

		for (SMII smii : candidates)
		{
			smii->second.visited = true;
			smii->second.cost_here = cost_so_far;
			found.push_back(smii);
			if (smii->second.goal) { finde_check = true; break; }
		}
	}

	if (!finde_check) { cout << "No_ \n"; return; }
	SMII pos = found.back();

	vector<Dir> path;
}



int main()
{
	MakeMap();
	FindGoalFrom(Pos(0, 0));
	
	for (int y = 0; y < MapHeight; y++)
	{
		for (int x = 0; x < MapWidth; x++)
		{
			cout << Map[y][x] << "\t";
		}
		cout << endl;
	}

	return 0;
}