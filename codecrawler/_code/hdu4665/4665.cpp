#include <cstdio>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn =2000+5;
int str1[maxn],str2[maxn];
int a[maxn],vis[maxn];
int n;
bool flag;
void dfs(int cur,int cnt1,int cnt2,int num)
{
    if(flag) return ;
    if(cnt1>n/2) return ;
    if(cnt1==n/2&&cnt2==n/2){
        flag=1;
        for(int i=0; i<n; i++)
            printf("%d",vis[i]);
        printf("\n");
        return;
    }
    if(a[cur]==str1[num])
    {
        str2[cnt2]=a[cur];
        if(num+1<=cnt1) vis[cur]=1,dfs(cur+1,cnt1,cnt2+1,num+1);
        vis[cur]=0;

    }
    str1[cnt1]=a[cur];
    dfs(cur+1,cnt1+1,cnt2,num);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        memset(vis,0,sizeof(vis));
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        str1[0]=a[0];
        flag=0;
        dfs(1,1,0,0);
    }
    return 0;
}