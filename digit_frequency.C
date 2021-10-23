#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

     
     char *s;
    s = malloc(1024*sizeof(char));
    scanf("%s",s);
    
    
    int k;
    int *a = malloc(sizeof(int)*10);
    
    
    for(int i=0; i<10; i++)
       a[i] = 0;
       
    for(int i=0; i<strlen(s); i++) 
    {
        k = s[i] - 48;
        if(k>=0 && k<10)
            a[k]++;
    } 
    for(int i=0; i<10; i++)
    {
        printf("%d ",a[i]);
    } 
    return 0;
}
   