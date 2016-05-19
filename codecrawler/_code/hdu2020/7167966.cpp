#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n, i;
    int f[103];
    int j, k, temp;
    scanf("%d",&n);
    while(n!=0)
    {
    for(i=1;i<=n;i++) scanf("%d",&f[i]);
    for(i=1;i<n;i++)
      {
        k=i;
        for(j=i+1;j<=n;j++)
           if(abs(f[j])>abs(f[k]) ) k =j;
        if(k!=i) {temp =f[i];f[i] =f[k]; f[k] =temp;}
      }
    for(i=1;i<n;i++) printf("%d ",f[i]);
    printf("%d\n",f[n]);
    scanf("%d",&n); 
    } 
    return 0;
}
  
