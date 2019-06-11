#include "Utill.h"



Utill::Utill()
{
}


Utill::~Utill()
{
}
int Utill::Clamp(int current, int Min, int Max)
{
	if (current < Min)
		return Min;

	if (current > Max)
		return Max;

	return current;
}