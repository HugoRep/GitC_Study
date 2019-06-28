#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main()
{
	int number = 0;
	
	cin >> number;

	cout << bitset<32>(number) << endl;

	//vector<int> result;
	//while (number != 0)
	//{
	//	//cout << number % 2;
	//	result.push_back(number % 2);
	//	number = number / 2;
	//}

	//for (int i = result.size() - 1; i >= 0; --i)
	//{
	//	cout << result[i];
	//}

	//for (int i = 31; i >= 0; --i)
	//{
	//	int bitmask = 1 << i;

	//	cout << ((number & bitmask) >= 1) ? 1 : 0;
	//	//if ((number & bitmask) >= 1)
	//	//{
	//	//	cout << 1;
	//	//}
	//	//else
	//	//{
	//	//	cout << 0;
	//	//}
	//}
}