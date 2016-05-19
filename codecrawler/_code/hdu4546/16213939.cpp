#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
int n,m,a[11111],k;
struct haha
{
    int sum;
    int nextsum;
    int nextid;
    bool operator<(const struct haha &b)const
    {return b.nextsum < nextsum;}
}temp,q;
void solve()
{
    sort(a,a+n);
    priority_queue<struct haha>que;
    q.sum=0;q.nextsum=a[0];q.nextid=0;
    que.push(q);
    int cnt=0;
    a[n]=0;
    while(cnt<m)
    {
        temp=que.top();
        que.pop();
        if(temp.nextid>=n) continue;
        q.sum=temp.sum;q.nextsum=temp.sum+a[temp.nextid+1];q.nextid=temp.nextid+1;
        que.push(q);
        q.sum=temp.nextsum;q.nextsum=temp.nextsum+a[temp.nextid+1];q.nextid=temp.nextid+1;
        que.push(q);
        cnt++;
    }
     for(int i = 0; !que.empty(); i ++) {a[i] = que.top().sum; que.pop();}
     sort(a,a+m);
     printf("Case #%d: %d\n",k,a[m-1]);
}
int main()
{
    int cas,i,j;
    scanf("%d",&cas);
    while(cas--)
    {
        k++;
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        solve();
    }
    return 0;
}
