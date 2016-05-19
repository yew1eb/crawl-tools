#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
int abst(int a,int b)
{
    int t=a-b;
    if(t>0)
        return t;
    else
        return 0-t;
}
int main()
{
    int ans;
    int n,m;
    int a,b;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&a,&b);
            ans^=(abst(a,b)-1);
        }
        if(ans==0)
        {
            printf("BAD LUCK!\n");
        }
        else
            printf("I WIN!\n");
    }
    return 0;
}