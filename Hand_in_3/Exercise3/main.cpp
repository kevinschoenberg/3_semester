#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Recursivly search for minimum value and maximum value
void minmax(int min, int max, int* a, int i)
{
	//When we have been through the whole array print min and max and return.
	if(i < 0)
	{
		cout << "min " << min << " max " << max << endl;
		return;
	} 
	//If current element is larger than current max change current element to current max.
	else if(a[i] > max)
	{
		max = a[i];
	}
	//If current element is lesser than current min change current element to current min.
	else if(a[i] < min)
	{
		min = a[i];
	}
	i--;
	//recursive step
	return minmax(min, max, a, i);
}

int main()
{

	//create random array of size s
	const int s = 10;
	int arr[s];
	srand(time(NULL));
	for(int i = 0; i < s; i++)
	{
		arr[i] = rand() % 100;
		cout << arr[i] << " ";
	}
	cout << endl;
	//test minmax function:
	minmax(arr[s-1], arr[s-1], arr, s-1);
	return 0;
}
