#include<iostream>
#include<cstdlib>
#include<stdio.h>
using namespace std;
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int ans=0;
        int a,b;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            ans^=abs(b-a)-1;
        }
        if(ans==0) puts("BAD LUCK!");
        else puts("I WIN!");
    }
}
