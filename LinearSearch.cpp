// Program to find an element in sorted vectors using linear search algorithm

#include <iostream>
#include <vector>

using namespace std;

int searching(vector<int> vec, int target)
{
    for(int i = 0 ; i < vec.size() ; i++)
    {
        if (vec[i] == target)
            return i;
    }
    
    return -1;
}

int main()
{
    vector<int> vec;
    int n, target, a;
  
    cout << "Enter the terms of array: " << endl;
    cin >> n;
    
    for(int  i = 0 ; i<n ; i++){
        cin >> a;
        vec.push_back(a);
    }
    
    cout << "Enter the target element: " << endl;
    cin >> target;
    
    int result = searching(vec, target);
    
    cout << "Target is at index: " << result << endl;
    
    return 0;
}
