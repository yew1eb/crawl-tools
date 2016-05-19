#include <stdio.h>
#include <string.h>
#include <iostream>
#define MAXL 50

using namespace std;

void plating(__int64 aniu[],int n);
int main()
{
    __int64 aniu[MAXL];
    //freopen("in.txt","r",stdin);
    int  n;
    plating(aniu,MAXL);
    while(scanf("%d",&n)!=EOF)
    {
        printf("%I64d\n",aniu[n]);
    }
    return 0;
}
void plating(__int64 aniu[],int n )
{
    aniu[1]=3;
    aniu[2]=8;
    int i;
    for(i=3; i<n; i++)
    {
        aniu[i]=2*aniu[i-1]+2*aniu[i-2];
    }
}
