#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSubarraySum(int arr[], int n) {
        long long max_No = INT_MIN, sum = 0;
        for (long long i = 0; i < n; i++)
        {
            sum = sum + arr[i];
            if (max_No < sum)
                max_No = sum;

            if (sum < 0)
                sum = 0;
        }
        return max_No;

    }
};

int main()
{
    int t, n;
    cin >> t; 
    while (t--) 
    {
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}