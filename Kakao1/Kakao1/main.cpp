#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n = 5;
	int arr1[5] = { 9, 20, 28, 18, 11 };
	int arr2[5] = { 30, 1, 21, 17, 28 };
	int result[5];

	string resultsSharp[5];

	for (int i = 0; i < 5; ++i)
	{
		result[i] = arr1[i] | arr2[i];
	}

	for (int i = 0; i < 5; ++i)
	{
		resultsSharp[i] = bitset<5>(result[i]).to_string();
		replace(resultsSharp[i].begin(), resultsSharp[i].end(), '1', '#');
		replace(resultsSharp[i].begin(), resultsSharp[i].end(), '0', ' ');
		cout << resultsSharp[i] << endl;
	}


	return 0;
}