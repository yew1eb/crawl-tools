#include <iostream>
#include <stdio.h>
using namespace std;

int sum, n, m;
int father[1000];

void makeset(int x)
{
    for(int i=1; i<=x; i++)
        father[i]=i;
}

int findset(int x)//æ¥æ¾
{
    if(x!=father[x])
        father[x]=findset(father[x]);//åæº¯ï¼è·¯å¾åç¼©
    return father[x];
}

void Union(int a, int b)//åå¹¶
{
    int x=findset(a);
    int y=findset(b);
    if(x==y)
        return;
    sum=sum-1;
    father[y]=x;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int j=1; j<=t; j++)
    {
        scanf("%d%d", &n, &m);
        sum=n;
        makeset(n);
        int first, second;
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d", &first, &second);
            Union(first, second);
        }
        printf("%d\n", sum);
        getchar();
    }
    return 0;

}
