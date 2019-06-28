#include "Engine.h"
#include "Map.h"
#include "Player.h"
#include "Utill.h"

int main()
{
	Engine* engine = new Engine();
	Player* player = new Player();
	Map* map = new Map();

	engine->init(player, map);
	//engine->Setting(new Setting(a, b, c, d));
	engine->Run();

	delete engine;
	return 0;
}