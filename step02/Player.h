#pragma once
class Player
{
public:
	Player();
	~Player();

	int X;
	int Y;

	void Move(int keyCode);
	void Tick(int keyCode);
	void Draw();
};