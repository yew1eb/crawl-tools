#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>

using namespace std;
const int N = 100005;
const int MOD = 1000000007;

struct node
{
    int id,val;
};

int n;
node a[N];
int aa[N],c[N],t[N];

bool cmp(node a,node b)
{
    return a.val < b.val;
}

int Lowbit(int x)
{
    return x & (-x);
}

void Update(int t,int val)
{
    for(int i=t; i<=n; i+=Lowbit(i))
    {
        c[i] += val;
        c[i] %= MOD;
    }
}

int getSum(int x)
{
    int ans = 0;
    for(int i=x; i>0; i-=Lowbit(i))
    {
        ans += c[i];
        ans %= MOD;
    }
    return ans;
}


int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(c,0,sizeof(c));
        memset(aa,0,sizeof(aa));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i].val);
            a[i].id = i;
        }
        sort(a+1,a+n+1,cmp);
        aa[a[1].id] = 1;
        for(int i=2;i<=n;i++)
        {
            if(a[i].val != a[i-1].val)
                aa[a[i].id] = i;
            else
                aa[a[i].id] = aa[a[i-1].id];
        }
        for(int i=1;i<=n;i++)
        {
            t[i] = getSum(aa[i]);
            Update(aa[i],t[i]+1);
        }
        printf("%d\n",getSum(n));
    }
    return 0;
}
