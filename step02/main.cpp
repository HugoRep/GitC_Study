
#include "Engine.h"
#include "Map.h"
#include "Player.h"
#include "Utill.h"


#define UP 75
#define DOWN 77
#define LEFT 72
#define RIGHT 80


int main()
{
	Engine* engine = new Engine();
	engine->Run();

	delete engine;
	return 0;
}