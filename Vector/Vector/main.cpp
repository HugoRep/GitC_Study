#include <iostream>
#include <vector>
#include "MyVector.h"
#include <time.h>


int main()
{
	int Size = 100000;
	int* a = new int[Size];

	std::vector<int> vInt;






	//vInt[1] = 1;
	//for (int i = 0; i < 1000; ++i)
	//{
	//	vInt.push_back(1);
	//}

	MyVector <int> v;

	for (int i = 0; i < 5; ++i)
	{
		v.PushBack(i );
	}

	v.InsertAfter(1, 10);
	v.InsertAfter(1, 20);


	//srand((unsigned int)time(0));
	//for (int i = 0; i < 30; ++i)
	//{
	//	v.Erase(rand() % v.GetSize());
	//}

	for (int i = 0; i < v.GetSize(); ++i)
	{
		std::cout << v[i] << std::endl;
	}



//	MyVector <float> v;
//
//	for (int i = 0; i < 100; ++i)
//	{
//		v.PushBack(i * 1.1f);
//	}
//
//	srand((unsigned int)time(0));
//	for (int i = 0; i < 30; ++i)
//	{
//		v.Erase(rand() % v.GetSize());
//	}
//
//	for (int i = 0; i < v.GetSize(); ++i)
//	{
//		std::cout << v[i] << std::endl;
////		std::cout << v.GetData(i) << std::endl;
//	}
//



	return 0;
}