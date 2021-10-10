#include<iostream>
using namespace std;


// To check if given number is power of 2 or not

int main(){

    int n;

    cout<<"Enter a number: ";
    cin>>n;

    if((n<1) or ((n&(n-1)))) {
        cout<<n<<" is not power of 2\n";
    }
    else{
        cout<<n<<" is power of 2\n";
    }

    
    
}
