#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n,m,x,y;
    while(scanf("%d %d %d %d",&n,&m,&x,&y)!=EOF)
    {
        if(n-x==x && y==m-y)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}