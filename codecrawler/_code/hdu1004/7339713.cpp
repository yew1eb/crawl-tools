#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
    int n;
    char ts[20];
    char str[1001][20];
    int  tot[1001];
    while(scanf("%d",&n),n)
    {
       memset(tot,0,sizeof(tot));
       getchar();
       for(int i=0;i<n;i++)
       {
           gets(str[i]);
           for(int j=0;j<=i;j++)
           {
               if(strcmp(str[i],str[j])==0)
                  tot[j]++;
           }
       }
       int max=-100,k;
       for(int i=0;i<n;i++)
       {
           if(tot[i]>max)
           {
               max=tot[i];
               k=i;
           }
       }
       puts(str[k]);
    }

    return 0;
}
