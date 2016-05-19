#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=110000;
int a[maxn],b[maxn];
long long sum[maxn];
int len=69;
void digt(long long x,int v)
{
    int i=0;
    while(x)
    {
        sum[i]+=v*(x+1)/2;
        x=x/2;
        i++;
    }
}
bool cmp(int x,int y)
{
    return a[len-x]<a[len-y];
}
int main()
{
    int t,op;
    scanf("%d",&t);
    long long l,r,k,ans;
    while(t--)
    {
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d",&a[++len]);
        }
        else
        {
            scanf("%I64d%I64d%I64d",&l,&r,&k);
            for(int i=0;i<=100;i++)
            sum[i]=0;
            digt(r,1);
            digt(l-1,-1);
            for(int i=0;i<=69;i++)
            b[i]=i;
            sort(b,b+70,cmp);
            ans=0;
            for(int i=0;i<70;i++)
            {
               // cout<<i<<"    "<<sum[b[i]]<<endl;
                if(ans+sum[b[i]]>=k)
                {
                    printf("%d\n",a[len-b[i]]);
                    break;
                }
                else
                {
                    ans+=sum[b[i]];
                }
            }
        }
    }
    return 0;
}
