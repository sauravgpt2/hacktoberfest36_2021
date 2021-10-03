#include<bits/stdc++.h>
using namespace std;

class Complex
{
  private:
    int a,b;
    public:
    void setData(int x,int y){
        a=x;
        b=y;
    }
    void showData(){
        cout<<a<<" + i"<<b;
    }
    Complex add(Complex c)
    {
        Complex temp;
        temp.a=a+c.a;
        temp.b=b+c.b;
        return(temp);
    }
};


int main()
{
    Complex c1,c2,c3;
    c1.setData(3,4);
    c2.setData(7,2);
    c3=c1.add(c2);
    c3.showData();
    return 0;
}


