#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void minmax(int min, int max, int* a, int i)
{
	if(i < 0)
	{
		cout << "min " << min << " max " << max << endl;
		return;
	} else if(a[i] > max)
	{
		max = a[i];
	} else if(a[i] < min)
	{
		min = a[i];
	} 
	i--;
	return minmax(min, max, a, i);
	
}

int main()
{
	int s = 10;
	int arr[s];

	srand(time(NULL));

	for(int i = 0; i < s; i++)
	{
		arr[i] = rand() % 100;
		cout << arr[i] << " ";
	}
	cout << endl;

	minmax(arr[s-1], arr[s-1], arr, s-1);
	return 0;
}
