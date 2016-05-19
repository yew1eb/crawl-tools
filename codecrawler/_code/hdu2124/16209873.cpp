#include <iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int L,N;
    int p[605];
    while(scanf("%d %d",&L,&N)!=EOF)
    {
       for(int i=0;i<N;i++)
            scanf("%d",&p[i]);
       sort(p,p+N,cmp);
       int ans=0;
        int i;
        for( i=0;i<N;i++)
        {
            ans+=p[i];
            if(ans>=L)break;
        }
        if(N==i)printf("impossible\n");
        else printf("%d\n",i+1);
    }
    return 0;
}
