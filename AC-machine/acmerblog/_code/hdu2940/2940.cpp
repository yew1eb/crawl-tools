#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;
const int M = 1009;
struct bt{
    int a[M];
    void init(){memset(a,0,sizeof(a));}
    void out()
    {
        for(int i=0;i<M;i++) cout<<a[i];cout<<endl;
    }
};
bt add(bt a,bt b)
{
    bt ans ;ans.init();
    int tmp = 0;
    for(int i=0;i<M;i++)
    {
        ans.a[i] = (a.a[i]+b.a[i]+tmp)%2;
        tmp = (a.a[i]+b.a[i]+tmp)/2;
    }
    return ans;
}
bt Multiply(bt a,bt b)
{
    bt tmp,ans;ans.init();
    for(int i=0;i<M;i++)
    if(a.a[i]==1)
    {
        tmp.init();
        for(int j=i;j<M;j++)
        tmp.a[j] = b.a[j-i];
        ans = add(ans,tmp);
    }
    return ans;
}
bt tobt(int k)
{
    bt ans;
    ans.init();
    for(int i=0;k;i++)
    ans.a[i]=k%2,k/=2;
    return ans;
}
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    while(scanf("%d",&n)&&n>=0)
    {
        if(n==0)
        {
            printf("0\n");continue;
        }
        bt t ;
        t = tobt(1);
        for(int i=2;i<=n;i++)
        t = Multiply(t,tobt(i));//,t.out();
        int f,ans=0;
        for(int i=M-1;i>=0;i--)
        if(t.a[i])
        {
            f= i;
            break;
        }
        for(int i=0;i<=f;i+=4)
        if(!t.a[i]&&!t.a[i+1]&&!t.a[i+2]&&!t.a[i+3])
        ans++;
        printf("%d\n",ans);
    }
    return 0;
}