#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

typedef long long LL;
const int N=101000;

char s[N];
int a[27];

struct xh
{
    int t;
    friend bool operator<(xh aa,xh bb)
    {
        return aa.t>bb.t;
    }
}w;

int main()
{
    int i,j,len,T,sum,n;
    cin>>T;
    while(T--)
    {
        scanf("%d%s",&n,s);
        len=strlen(s);
        memset(a,0,sizeof(a));
        for(i=0;i<len;i++)
            a[s[i]-'a']++;
        priority_queue<xh> q;
        len=0;
        for(i=0;i<26;i++)
            if(a[i])
            {
                w.t=a[i];
                q.push(w);
                len++;
            }
        if(len==1)
        {
            sum=q.top().t;
        }
        else
        {
            int i=0;
            sum=0;
            while(i<len-1)
            {
                int x=q.top().t;
                q.pop();
                int y=q.top().t;
                q.pop();
                sum+=x+y;
                w.t=x+y;
                q.push(w);
                i++;
            }
        }
        if(sum<=n)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
