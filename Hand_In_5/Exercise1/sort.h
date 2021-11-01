#ifndef _SORT_H_
#define _SORT_H_

#include <vector>
using namespace std;

/**
 *
 * Several sorting routines.
 * Arrays are rearranged with smallest item first.
 */


template<typename T>
void selectSort(vector<T> &a)
{
    int min; // O(1)
    T temp; // O(1)
    for (int i = 0; i < a.size() - 1; i++) // O(N)
    {
        min = i; // O(1)
        for (int j = i + 1; j < a.size(); j++) // (N-1)/2 = O(N)
        {
            if(a[j] < a[min]) // O(1)
            {
                min = j; // O(1)
            }
        }
        temp = a[i]; // O(1)
        a[i] = a[min]; // O(1)
        a[min] = temp; // O(1)
    }
}
#endif

//Combined we get O(N^2)