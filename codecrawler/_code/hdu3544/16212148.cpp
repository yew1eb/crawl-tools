#include<iostream>
#include<cstdlib>
#include<stdio.h>
#define ll __int64
using namespace std;
int main()
{
    int t,n;
    int count=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ll x,y;
        ll c1=0,c2=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%I64d%I64d",&x,&y);
            while(x>1&&y>1)
            {
                x>>=1;y>>=1;
                c1++;c2++;
            }
            if(x==1) c2+=y-1;
            else c1+=x-1;
        }
        printf("Case %d: ",count++);
        if(c1>c2) puts("Alice");
        else puts("Bob");
    }
}
