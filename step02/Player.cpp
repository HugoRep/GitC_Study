#include "Player.h"
#include "Utill.h"
#include "KeyBoardConst.h"
#include <stdio.h>


Player::Player()
{
}


Player::~Player()
{

}

void Player::Move(int keyCode )
{
	switch (keyCode)
	{
	case KeyBoardConst::UP:
		X--;
		break;
	case KeyBoardConst::DOWN:
		X++;
		break;
	case KeyBoardConst::LEFT:
		Y--;
		break;
	case KeyBoardConst::RIGHT:
		Y++;
		break;
	}

	X = Utill::Clamp(X, 1, 8);
	Y = Utill::Clamp(Y, 1, 8);
}


void Player::Tick(int keyCode)
{
	Move(keyCode);
}

void Player::Draw()
{
	printf("@");
}
