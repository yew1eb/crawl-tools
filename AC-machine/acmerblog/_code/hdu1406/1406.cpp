#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 10010
int a[N];
int flag[N];
void Fuck()
{
    memset(a,0,sizeof(a));
    memset(flag,0,sizeof(flag));
    for(int i=1;i<=N;i++)
    for(int j=2*i;j<=N;j+=i)
    a[j]+=i;
    for(int i=1;i<=N;i++)
    if(a[i]==i)
    flag[i]=1;
}
int main()
{
    int t;
    scanf("%d",&t);
    Fuck();
    while(t--)
    {
        int x,y;
        int count=0;
        scanf("%d%d",&x,&y);
        if(x>y)
        swap(x,y);
        for(int i=x;i<=y;i++)
        if(flag[i])
        count++;
        printf("%d\n",count);
    }
    return 0;
}