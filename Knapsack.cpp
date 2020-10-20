#include<bits/stdc++.h>
using namespace std;
int max(int a, int b)
{
return (a > b)? a : b;
}
int knapSack(int W, int wt[], int profit[], int n)
{
   int i, w;
   int **K, *sol;
   K = new int*[n+1];
   sol = new int[n];
   for(i=0;i<n+1;i++){
K[i] = new int[W+1];
   }

   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
  if (i==0 || w==0)
      K[i][w] = 0;
  else if (wt[i-1] <= w)
K[i][w] = max(profit[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
  else
K[i][w] = K[i-1][w];
       }
   }
   cout<<"\n DP Table:\n";
   for(int i=0;i<=n;i++){
       for(int w=0;w<=W;w++){
           cout<<K[i][w]<<" ";
       }
       cout<<"\n";
   }
   
   cout<<"\n";
cout<<"Item number in solution : ";
   int res = K[n][W];

   w = W;
  /* for (i = n; i >= 0 && res >= 0; i--) {
if (res == K[i - 1][w])
   cout<<"0 ";
else {
cout<<"1 ";
   res = res - profit[i - 1];
   w = w - wt[i - 1];
}
    }*/
    
   for (i = n; i > 0 && res > 0; i--) {
if (res == K[i - 1][w])
   continue;
else {
cout<<i<<"\t";
   res = res - profit[i - 1];
   w = w - wt[i - 1];
}
    }
   return K[n][W];
}

int main()
{
    int *profit, *weight;
    int  W,n,i;

cout<<"Enter number of items :";
cin>>n;
    profit = new int[n];
    weight = new int[n];
cout<<"\nEnter value of weight and profit :";
    for(i=0;i<n;i++){
cin>>weight[i]>>profit[i];
    }
cout<<"\nEnter capacity of knapsack :";
cin>>W;
cout<<"\nSolution : "<<knapSack(W, weight, profit, n);

    return 0;
}
