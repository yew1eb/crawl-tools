//#pragma comment(linker,"/STACK:65536000")
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<string>
#include<list>
#include<set>
#include<map>
#include<queue>
#include <math.h>
#define clr(x,y) memset(x,y,sizeof(x))
#define forn(i,n) for(int i=0;i<n;i++)
#define ll long long
#define mpr(x,y) make_pair(x,y)
#define pii pair<int,int>
#define MID ((l+r)>>1)
#define lson rt<<1,l,MID
#define rson rt<<1|1,MID+1,r
#define D(a) ((a)>0?(a):-(a))
#define sqr(a) ((a)*(a))
#define lowb(i) ((i)&(-i))
using namespace std;
const int inf=1<<30;

int n,m,o;
char a[10000];
int T[1000];
vector <int> in[1000],out[1000];
int num[1000];
int first[1000],next[1000],v[1000],ed;
void addedge(int u,int v){
    ::v[ed]=v;
    next[ed]=first[u];
    first[u]=ed++;
}
struct my{
    int x,d,s;
    my(int x=0,int d=0,int s=0):x(x),d(d),s(s){}
    bool operator <(const my &u)const{
        return s>u.s;
    }
};
int ti=1;

string dfs(int u){
    string ans="(";
    if(u!=0){
        char b[10]="P";
        sprintf(b+1,"%d",u);
        ans+=b;
    }
    if(first[u]!=-1){
        ans+="(";
        int f=1;
        for(int i=first[u];~i;i=next[i]){
            if(f)f=0;
            else ans+="|";
            ans+=dfs(v[i]);
        }
        ans+=")";
    }
    ans+=")";
    if(ans.length()>10000)while(1);
    return ans;
}
void gao(){
    priority_queue <my> que;
    bool vis[1000]={0};
    int dis[1000];
    for(int i=1;i<=n;i++)dis[i]=inf;
    dis[0]=0;
    for(int i=1;i<=n;i++){
        int flag=1;
        for(int j=0;j<(int)in[i].size();j++)if(a[in[i][j]]=='0'){
            flag=0;break;
        }
        if(flag){
            vis[i]=1;
            addedge(0,i);
            dis[i]=min(dis[i],T[i]);
            que.push(my(i,T[i],dis[i]));
        }
    }
    int ans=-1;
    while(!que.empty()){
        my now=que.top();que.pop();
        int x=now.x;
        for(int i=0;i<(int)out[x].size();i++){
            if(a[out[x][i]]!='1'){
                a[out[x][i]]='1';
                num[out[x][i]]=x;
            }
        }
        if(a[o]=='1'){
            ans=dis[x];
            break;
        }
        for(int i=1;i<=n;i++)if(!vis[i]){
            int flag=1;
            for(int j=0;j<(int)in[i].size();j++)if(a[in[i][j]]=='0'){
                flag=0;break;
            }
            if(flag){
                vis[i]=1;
                int p=0;
//                addedge(x,i);
                int ret=0;
                for(int j=0;j<(int)in[i].size();j++)if(dis[num[in[i][j]]]>ret)ret=dis[num[in[i][j]]],p=num[in[i][j]];
                addedge(p,i);
                dis[i]=min(dis[i],ret+T[i]);
                que.push(my(i,T[i],dis[i]));
            }
        }
    }
//    for(int i=0;i<=n;i++){
//        printf("%d : ",i);
//        for(int j=first[i];~j;j=next[j])printf("%d ",v[j]);
//        puts("");
//    }
    if(ans!=-1){
        printf("Case %d: %d ",ti++,ans);
        cout<<dfs(0)<<endl;

    }
    else printf("Case %d: %d\n",ti++,ans);
    puts("");
}
int main(){
//    freopen("/home/axorb/in","r",stdin);
    while(scanf("%d%d%d",&n,&m,&o),n+m+o){
        scanf("%s",a+1);
        ed=0;
        clr(first,-1);
        clr(num,0);
        for(int i=1;i<=m;i++)if(a[i]=='1')num[i]=0;
        for(int i=1;i<=n;i++){
            scanf("%d",T+i);
            in[i].clear();
            out[i].clear();
            int p;
            scanf("%d",&p);
            for(int j=0;j<p;j++){
                int q;
                scanf("%d",&q);
                in[i].push_back(q);
            }
            scanf("%d",&p);
            for(int j=0;j<p;j++){
                int q;
                scanf("%d",&q);
                out[i].push_back(q);
            }
        }
        gao();
    }
}