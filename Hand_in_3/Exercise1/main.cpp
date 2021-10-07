#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Method to find a pair in a vector
void findPair(vector<int> v, int target)
{
    //create itterator
    vector<int>::iterator itr;

    //Consider each element in the vector except the last.
    for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
    {
        itr = find(v.begin(), v.end(), target - *i);
        //If the desired pair is found. Print the pair.
        if (itr != i && itr != v.end())
        {
            cout << "found pair: " << *i << " " << *itr << endl;
            return;
        }
    }
    //This os reached iff the pair was not found
    cout << "no pair found" << endl;
}

int main()
{
    //Test code:
    //Create Vector
    vector<int> v;
    v.push_back(8);
    v.push_back(7);
    v.push_back(2);
    v.push_back(5);
    v.push_back(3);
    v.push_back(1);

    //set target
    int target = 8;

    //find pair
    findPair(v, target);

    return 0;
}
