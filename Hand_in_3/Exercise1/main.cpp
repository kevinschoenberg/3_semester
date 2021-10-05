#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findPair(vector<int> v, int target)
{
    vector<int>::iterator itr;
    for (vector<int>::iterator i = v.begin(); i < v.end(); i++)
    {
        itr = find(v.begin(), v.end(), target - *i);
        if (itr != i && itr != v.end())
        {
            cout << "found pair: " << *i << " " << *itr << endl;
            return;
        }
    }
    cout << "no pair found" << endl;
}

int main()
{
    vector<int> v;
    vector<int>::iterator itr;

    v.push_back(8);
    v.push_back(7);
    v.push_back(2);
    v.push_back(5);
    v.push_back(3);
    v.push_back(1);

    int target = 10;

    int n = v.size();

    findPair(v, target);

    return 0;
}
