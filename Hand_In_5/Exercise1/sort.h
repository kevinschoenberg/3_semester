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
    int min;
    T temp;
    for (int i = 0; i < a.size(); i++)
    {
        min = i;
        for (int j = i + 1; j < a.size(); j++)
        {
            if(a[j] < a[min])
            {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

#endif