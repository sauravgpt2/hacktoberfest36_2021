#include <bits/stdc++.h>
#include<string>
using namespace std;
int main(){
      string s,g;
      int n;
      cin>>s;
      g=s;
      reverse(s.begin(), s.end());
      if(s==g){
         cout<<"The string is palindrome";
      }
      else{
         cout<<"The string is not palindrome";
      }
}
