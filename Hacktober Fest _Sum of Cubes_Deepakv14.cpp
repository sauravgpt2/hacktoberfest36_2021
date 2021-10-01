/*   SUM OF CUBES ( Codeforces Round #702 (Div.3)
You are given a positive integer x. Check whether the number x is representable as the sum of the cubes of two positive integers.

Formally, you need to check if there are two integers a and b (1<=a,b) such that a3+b3=x.

For example, if x=35, then the numbers a=2 and b=3 are suitable (23+33=8+27=35). If x=4, then no pair of numbers a and b is suitable.

Input
The first line contains one integer t (1<=t<=100) — the number of test cases. Then t test cases follow.

Each test case contains one integer x (1<=x<=10^12).

Please note, that the input for some test cases won't fit into 32-bit integer type, so you should use at least 64-bit integer type in your programming language.

Output:
For each test case, output on a separate line:
a)"YES" if x is representable as the sum of the cubes of two positive integers.
b)"NO" otherwise.

You can output "YES" and "NO" in any case (for example, the strings yEs, yes, Yes and YES will be recognized as positive).
*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<str> vs;
typedef vector<vector <int> > vvi;
typedef vector<vector <ll> > vvl;

const ll remi=1000000007;
const ll remi2=998244353;
const ll inf=1e18+1e17+1e16+1e15+1e14;
const ll N = 1'000'000'000'000L;

#define pi 3.141592653589
#define pb push_back
#define F first
#define S second
#define el "\n"
#define sp " "
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);ll i;
    unordered_set<ll> s; // set containing cube of all possible numbers
    for(i=1;i*i*i<=N;i++)
    s.insert(i*i*i);
    ll t;
    cin>>t;
    while(t--)
    {
    	ll x,count=0;
    	cin>>x;
    	for(ll b=1;b*b*b<=x;b++)
    	{
    		if(s.count(x-b*b*b)) 
       	{    //  if found
    		cout<<"YES"<<el;
    		count++;
		break;	
	    }
	   
        }
         if(count==0)
	    cout<<"NO"<<el;
    }
    return 0;
}
