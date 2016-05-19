#include<stdio.h>
#include<string.h>
bool f[10001],ff[1010001];
int a[5];
int main()
{
    int i,j,k,max,cas,t,x,count,flag;
    scanf("%d",&cas);
    while(cas--)
    {
    memset(f,0,sizeof(f));
    k=0;
    for(i=1;i<=4;i++) 
    {
    scanf("%d",&x);    
    if(f[x]==0) {a[++k]=x;f[x]=1;}
    }
/*
    for(i=1;i<=k;i++)
    printf("%d ",a[i]);
    printf("\n\n");
  */  
    memset(ff,0,sizeof(ff));
    ff[0]=1;count=1;max=0;
    for(i=1;i<=1000000;i++)
    {
      flag=0;
      for(j=1;j<=k;j++)
      {
      if(i-a[j]>=0&&ff[i-a[j]]==1)
      {ff[i]=1;count++;flag=1;break;}      
      }    
      if(flag==0) {max=i;/*printf("%d\n",i);*/}
    }
    
    t=0;
    for(i=1000000+1;i<=1010000;i++)
    {
       flag=0;
       for(j=1;j<=k;j++)
       if(i-a[j]>=0&&ff[i-a[j]]) {flag=1;ff[i]=1;break;}
       if(flag==0)
       {t=1;break;}        
    }
    if(t) printf("%d\n-1\n",1000001-count);
    else printf("%d\n%d\n",1000001-count,max);
    }    
}
/*
300
8 5 9 7
5 8 5 5
1938 1939 1940 1937
*/