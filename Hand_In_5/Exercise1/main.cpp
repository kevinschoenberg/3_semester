#include "sort.h"
#include <iostream>
#include <vector>
using namespace std;
template<class T>

void show(vector<T> v)
{
	for (T i:v)
		cout << v[i] << " ";
}

int main()
{
    vector<int> a = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
	cout << "The array before sorting is : \n";
	show(a);
    cout << endl;

	selectSort(a);

	cout << "\n\nThe array after sorting is :\n";
	show(a);
	return 0;
}