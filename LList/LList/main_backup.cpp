//#include <iostream>
//#include <list>
//#include <vector>
//#include <algorithm>
//#include "LList.h"
//
//using namespace std;
//
//int main()
//{
//	list<int> a;
//
//	LList<float> l;
//	for (int i = 1; i <= 10; ++i)
//	{
//		l.PushBack(i *1.1f);
//	}
//
//	for (LList<float>::Iterator CurrentPosition = l.Begin(); CurrentPosition != l.End(); CurrentPosition++)
//	{
//		CurrentPosition = l.Erase(CurrentPosition);
//	}
//
//	for (LList<float>::ReverseIterator CurrentPosition = l.RBegin(); CurrentPosition != l.REnd(); CurrentPosition++)
//	{
//		cout << (*CurrentPosition)->Value << endl;
//	}
//
//	
//
// 	return 0;
//}