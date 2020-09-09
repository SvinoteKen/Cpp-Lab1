#include <iostream>
#include <iomanip>
using namespace std;
int Factorial(int x)
{
	int num = 1;
	for (int i = 1; i <= x; i++) 
	{
		num = num * i;
	}
	return num;
}
void InitializeArray(int** x, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			*(*(x + i) + j) = Factorial(i) + Factorial(j);
		}
	}
}
void PrintArray2D(int** x, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(8) << *(*(x + i) + j);
		}
		cout << endl;
	}
	cout << endl;
}
int* MakeArray1D(int** x, int n, int m) 
{
	int cnt = n;

	int* y = new int[cnt * m];
	int k = 0;
	for (int i = 1; i < n; i += 2)
	{
		for (int j = 0; j < m; j++, k++)
		{
			*(y + k) = *(*(x + i) + j);
			cout << *(y + k) << " ";
		}
	}
	return y;

}
void FreeArr2D(int** x, int n)
{
	for (int i = 0; i < n; i += 2)
	{
		delete[] * (x + i);
	}
}

void FreeArr1D(int* y)
{
	delete[] y;
}
int main()
{
	const size_t N = 5;
	const size_t M = 5;

	int** arr2D = new int* [5];
	for (int i = 0; i < N; i++)
	{
		*(arr2D + i) = new int[M];
	}

	InitializeArray(arr2D, N, M);
	PrintArray2D(arr2D, N, M);
	MakeArray1D(arr2D, N, M);

	int* arr1D = MakeArray1D(arr2D, N, M);

	FreeArr2D(arr2D, 5);
	FreeArr1D(arr1D);
}
