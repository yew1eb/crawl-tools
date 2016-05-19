#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
#include<iostream>
#include<list>
#include<set>
#include<cmath>
#define INF 0x7fffffff
#define eps 1e-6
#define LL long long
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a,b,m=0,tmp;
        scanf("%d",&a);
        for(int i=1;i<n;i++)
        {
            scanf("%d",&b);
            if(m<abs(a-b))
                m=abs(a-b),tmp=i;
            a=b;
        }
        printf("%d %d\n",tmp,tmp+1);
    }
}
