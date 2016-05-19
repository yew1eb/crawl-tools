#include<iostream>
#include<cstdio>
using namespace std;
const int N=200002;
int a[N];
int main()
{
    int m,sum,s,i;
    while(scanf("%d",&m)!=EOF&&m)
    {
        sum=0;
        for(i=0;i<m;i++)
        { 
            scanf("%d",&a[i]);
            sum=sum^a[i];
        }
        if(sum==0) printf("No\n");
        else
        {
           printf("Yes\n");
           for(i=0;i<m;i++)
           {
               s=sum^a[i];
               if(s<a[i])
                   printf("%d %d\n",a[i],s);
           
           }
        
        }
    
    }
   return 0;
}