#include <iostream>
#include <string>
#include "LList.h"

using namespace std;
//
//class StackIter;
//class ShoeCloseInterator;
//
//class Shoes
//{
//private :
//	string name;
//public : 
//	string GetName()
//	{
//		return name;
//	}
//
//	void SetName(string  name)
//	{
//
//	}
//};
//
//
//
//
//class ShoeCloset 
//{
//	friend class ShoeClosetIterator;	
//private : 
//	Shoes shoesBoxs[5];
//	int size;
//public:
//	ShoeCloset() {
//		size = 5;
//		shoesBoxs[0].SetName("A");
//		shoesBoxs[1].SetName("B");
//		shoesBoxs[2].SetName("C");
//		shoesBoxs[3].SetName("D");
//		shoesBoxs[4].SetName("E");
//	};
//
//	Shoes* getShoesBox() { return shoesBoxs; }
//	int getSize() { return size; }
//
//	ShoeClosetIterator* createIterator() const;
//};
//
//
//
//
//
//class ShoeClosetIterator
//{
//private :
//	const ShoeCloset* pShoeCloset;
//	int index;
//
//public:
//	ShoeClosetIterator(const ShoeCloset* _pShoeCloset) 
//	{
//		pShoeCloset = _pShoeCloset; 
//	}
//	void first() 
//	{ 
//		index = 0; 
//	}
//	void next() 
//	{
//		++index; 
//	}
//	bool isDone() 
//	{
//		return index == pShoeCloset->size; 
//	}
//
//	Shoes currentItem() 
//	{
//		return pShoeCloset->shoesBoxs[index]; 
//	}
//};
//
//

int main()
{
	/*ShoeCloset shoesCloset;

	ShoeClosetIterator* i;

	for (i = shoesCloset.createIterator(); i->isDone(); i->next())
	{
		cout << i->currentItem().GetName() << endl;
	}*/
	LList<int> l;
	l.Insert(1);
	return 0;
}

