#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<math.h>
using namespace std;
int find(int s,int c)
{
    int p=sqrt(s+0.0);
    while(p+p*p>=s) p--;
    if(c>p) return s-c;
    else return find(p,c);
}
int main()
{
    int count=1;
    int n;
    while(scanf("%d",&n)&&n)
    {
        int ans=0;
        int s,c;
        while(n--)
        {
            scanf("%d%d",&s,&c);
            ans^=find(s,c);
        }
        printf("Case %d:\n",count++);
        if(ans) puts("Yes");
        else puts("No");
    }
}
