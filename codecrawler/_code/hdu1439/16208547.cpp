#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int SIZEN=205;
int a[SIZEN];
bool vis[SIZEN];
char str[SIZEN],ans[SIZEN];
int cir[SIZEN],cnt;
void init(){
    memset(str,' ',sizeof(str));
    memset(vis,0,sizeof(vis));
}
void dfs(int u){
    if(vis[u]) return;
    vis[u]=1;
    cir[cnt++]=u;
    dfs(a[u]);
}
void solve(int n){
    int k;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    while(scanf("%d",&k)!=EOF&&k){
        init();
        gets(str);
        int len=strlen(str);
        for(int i=len;i<=n;i++) str[i]=' ';
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                cnt=0;dfs(i);
                int t=k%cnt;
                //printf("cnt:%d t:%d\n",cnt,t);
                //for(int j=0;j<cnt;j++) printf("%d ",cir[j]);printf("\n");
                for(int j=0;j<cnt;j++){
                    ans[cir[(j+t)%cnt]]=str[cir[j]];
                    //printf("%d %d\n",cir[(j+t)%cnt],cir[j]);
                    //printf("%c\n",str[cir[j]]);
                }
            }
        }
        for(int i=1;i<=n;i++) printf("%c",ans[i]);
        printf("\n");
    }
    return;
}
int main()
{
    int n,flag=0;
    while(scanf("%d",&n)!=EOF&&n){
        solve(n);
        printf("\n");
    }
    return 0;
}