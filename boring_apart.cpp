#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int t=0,i=0;
	cin>>t;
	for(i=0;i<t;i++)
	{
		int x,y=1,count=0,z=0,a=0;
		
		cin>>x;
		count=log10(x);
		y=x/pow(10,count);
		
		while(x!=0)
		{
			x=x/10;
			z++;
		}
		a=(y-1)*10;
		while(z>0)
		{
			a=a+z;
			z--;
		}
		cout<<a<<"\n";
	}
}
