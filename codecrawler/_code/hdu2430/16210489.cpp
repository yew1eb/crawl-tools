#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Node{
    int x,pos;
}a[2000010],s[2000010];
int cmp(Node a,Node b)
{
    if(a.x!=b.x) return a.x<b.x;
    return a.pos<b.pos;
}
int f[2000010];
int main()
{
    int T,n,p,K,cas;
    cas=1;f[0]=0;
    for(cin>>T;T--;)
    {
        scanf("%d%d%d",&n,&p,&K);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&f[i]);
            f[i]=f[i]+f[i-1];
            a[i].x=f[i]%p;
            a[i].pos=i;
        }
        sort(a+1,a+n+1,cmp);
        int ans=-1;   int temp=0;int top=0;int tail=0;int last=0;
        for(int k=1;k<=n;k++)
        {
            while(top<tail&&a[k].pos<s[tail-1].pos) tail--;
            s[tail++]=a[k];
            //cout<<a[k]<<' '<<a[s[top]]<<' '<<k<<endl;
            while(top<tail&&a[k].x-s[top].x>K) top++;
            int t=a[k].pos;

            if(f[t]%p<=K) ans=max(ans,f[t]/p);
            else if(top<tail&&s[top].pos<t)
            {
                ans=max(ans,(f[t]-f[s[top].pos])/p);
            }
        }
        printf("Case %d: ",cas++);
        printf("%d\n",ans);
    }
    return 0;
}
