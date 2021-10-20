#include<iostream>
#include<vector>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int 
#include<algorithm>

using namespace std;

template <class T>

void display(vector<T> &v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    
}

int main(){

vector<int> vec1;
vector<char> vec2(7,'e');
int size,element;
cout<<"enetr size";
cin>>size;

for (int i = 0; i < size; i++)
{
    cin>>element;
    vec1.push_back(element);
}
//write iterator line and repla
//vector<int> ::iterator iter = vec1.begin();
    vec1.insert(vec1.begin()+2,32);
display(vec1); 
cout<<endl<<vec1.at(2)<<endl;
display(vec2);
return 0;
}
