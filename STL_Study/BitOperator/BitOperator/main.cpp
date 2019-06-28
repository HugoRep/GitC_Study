#include <stdio.h>
#include <bitset>
#include <iostream>
#include <typeinfo.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	/*unsigned long long int inputA;
	unsigned long long int inputB;
	unsigned long long int inputC;

	unsigned long long int value;
	vector<long long int> Storage;

	cin >> inputA;
	cin >> inputB;
	cin >> inputC;

	bitset<64> b1(inputA);
	bitset<64> b2(inputB);
	bitset<64> b3(inputC);

	b3 ^= (b1 ^= b2);
	
	cout << b3.to_ulong() << "\n";*/

	int a = 5;
	int arr1[5] = { 9, 20, 28, 18, 11 };
	int arr2[5] = { 30, 1, 21, 17, 28 };
	int result[5];

	string resultSharp[5];

	for (int i = 0; i < 5; i++)
	{
		result[i] = arr1[i] | arr2[i];
	}

	for (int i = 0; i < 5; i++)
	{
		resultSharp[i] = bitset<5>(result[i]).to_string();
		replace(resultSharp[i].begin(), resultSharp[i].end(), '1', '#');
		replace(resultSharp[i].begin(), resultSharp[i].end(), '0', ' ');
		cout << resultSharp[i] << endl;
	}
	return 0;
}