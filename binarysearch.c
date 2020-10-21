#include<stdio.h>
#include<conio.h>>
int main(){
 int n,*p,a,ans,count=0;
 printf("enter the size ");
 scanf("%d",&n);
 p=(int*)malloc(sizeof(int)*n);
 int i;
 
 for(i=0;i<n;i++){
    scanf("%d",(p+i));

 }
 printf("enter the number which we want to find ");
 scanf("%d",&a);
 ans=bs(a,count,n-1,p);
 if(ans==-1){
 	printf("No such element is found");
 }else{
 printf("%d",ans);
}
 
 return 0;
}
int bs(int a,int count,int n,int *p){
    int m=(count+n)/2 + 1;
    if(a==*(p+m))
        return m;
    else if(a>*(p+m))
        bs(a,m+1,n,p);
    else if(a<*(p+m))
        bs(a,count,m-1,p);
    else if(count>n-1)
           	printf("No such element is found");
	
}
