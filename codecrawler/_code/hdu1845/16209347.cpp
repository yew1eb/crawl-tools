#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
const int maxn=5010;
using namespace std;

int main()
{
    int n,a,b,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<3*n/2;i++)
            scanf("%d%d",&a,&b);
        printf("%d\n",n/2);
    }
    return 0;
}