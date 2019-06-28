#include <iostream>
#include <stack>
#include <array>
#define MAX 10

using namespace std;
int Image[MAX][MAX] = 
{
	{1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
	{1, 1, 1, 1, 0, 0, 0, 0, 1, 1},
	{1, 1, 1, 1, 0, 1, 1, 0, 1, 1},
	{1, 1, 1, 1, 0, 1, 1, 0, 1, 1},
	{1, 1, 1, 1, 0, 1, 1, 0, 1, 1},
	{1, 1, 0, 0, 0, 1, 1, 0, 1, 1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
};

int CountImage(int x, int y)
{
	if (x < 0 || y < 0 || x >= MAX || y >= MAX)
	{
		return 0;
	}
	else if (Image[y][x] != 1 )
	{
		return 0;
	}
	else
	{
		Image[y][x] = -1;
		return 1 + CountImage(x + 1, y) +
			CountImage(x, y + 1) +
			CountImage(x - 1, y) +
			CountImage(x, y - 1) +
			CountImage(x - 1, y - 1) +
			CountImage(x + 1, y + 1) +
			CountImage(x + 1, y - 1) +
			CountImage(x - 1, y + 1);
	}
}

void Swap(int &a, int &b)
{
	int Temp = a;
	a = b;
	b = Temp;
}
void SelectionSort(int *Data, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (Data[i] > Data[j])
			{
				Swap(Data[i], Data[j]);
			}
		}
	}
}


bool cmp(int a, int b)
{
	return a < b;
}

bool cmp2(int a, int b)
{
	return a > b;
}

void BubbleSort(int *Data, int size, bool (*fp)(int ,int))
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 1; j < size-1; j++)
		{
			if (cmp(Data[i] , Data[j+1]))
			{
				Swap(Data[i], Data[j+1]);
			}
		}
	}
}
int partition(int *Data, int begin, int end , bool(*fp)(int, int))
{
	
	int pivot = Data[end];
	stack<int> stack;
	

	cout << "pivot : " << pivot << endl;
	
	for (int i = begin; i < end; i++)
	{
		if (fp(pivot , Data[i]))
		{
			cout << Data[i] << " , ";
			stack.push(Data[i]);
		}
	}
	
	cout << endl;
	cout << "---------------------------" << endl;
	//cout << "stack top: " << stack.top() << endl;
	
	return stack.top();
}

void QuickSort(int *Data, int begin, int end)
{
	if(begin < end) 
	{
		//int pivot1 = partition(Data, begin, end , cmp);
		int pivot2 = partition(Data, begin, end, cmp2);
		
		//QuickSort(Data, begin, pivot1 - 1);
		//cout << pivot2 << end << endl;
		QuickSort(Data, pivot2 + 1 , end);
	}
}




int main()
{
	//cout << CountImage(3, 0) << endl;
	int num[10] = { 2,3,13,45,6,5,7,68,9,5 };

	for (int i = 0; i < 10; i++)
	{
		cout << num[i] << " ,";
	}
	cout << endl;
	//SelectionSort(num, 10);

	//BubbleSort(num, 10 ,cmp);

	QuickSort(num, 0, 9 );
	
	for (int i = 0; i < 10; i++)
	{
		cout << num[i] << " ,";
	}
	cout << endl;

	return 0;
}