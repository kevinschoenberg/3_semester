#include "sort.h"
#include <iostream>
#include <vector>
using namespace std;
template<class T>

void show(vector<T> v)
{
	for (T i:v)
		cout << v[i] << " ";
	cout << endl;
}

int main()
{
    vector<int> a = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
	cout << "The array before sorting is : " << endl;
	show(a);
    cout << endl;

	selectSort(a);

	cout << "The array after sorting is :" << endl;
	show(a);
	return 0;
}