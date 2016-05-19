#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
inline int max(int a ,int b){return a>b?a:b;}
const int N = 100010;
int s1[N],s2[N];
int a[N];
int main()
{
    int n,m,k,top1,top2,last1,last2,tail1,tail2,ans;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        memset(s1,0,sizeof(s1));
        memset(s2,0,sizeof(s2));
        top1=0;top2=0;tail1=0;tail2=0;ans=0;last1=0;last2=0;
        for(int i=1;i<=n;i++)
        {
            //max
            while(top1<tail1&&a[s1[tail1-1]]<=a[i])tail1--;  //top1æå¤§åç´ 
            s1[tail1++]=i;
            //min
            while(top2<tail2&&a[s2[tail2-1]]>=a[i])tail2--;  //top2æå°åç´ 
            s2[tail2++]=i;

            while(a[s1[top1]]-a[s2[top2]]>k)
            {
                if(s1[top1]<s2[top2])
                last1=s1[top1++];
                else last2=s2[top2++];
            }
            if(a[s1[top1]]-a[s2[top2]]>=m)
            {
                ans=max(ans,i-max(last1,last2));
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}
