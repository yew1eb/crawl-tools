#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define MM(a,b,c) memset(a,b,sizeof(a[0])*(c+2))
using namespace std;
const int SIZEN=10005;
struct edge{
    int to,next;
};
edge e[SIZEN];
int val[SIZEN];
int head[SIZEN],sz,in[SIZEN];
int right[15],t_val[15];
int ll,cnt,bit[1050];
vector<int> num[15];
double fm;
void getbit(){
    for(int i=1;i<1024;i++){
        int ti=i;
        for(int j=0;j<10;j++){
            bit[i]+=ti&1;
            ti>>=1;
        }
    }
}
void init(int n){
    MM(head,-1,n);
    MM(in,0,n);
    sz=ll=cnt=0;
}
void addedge(int u,int v){
    e[sz].to=v;
    e[sz].next=head[u];
    head[u]=sz++;
    in[v]++;
}
void dfs(int u,int id){
    num[id].push_back(u);
    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].to;
        dfs(v,id);
    }
}
void rebuild(int n){
    for(int i=0;i<n;i++)
        if(!in[i]){
            num[cnt].clear();
            dfs(i,cnt);
            ll=max(ll,(int)num[cnt].size());
            cnt++;
        }
}
void debug1(){
    for(int i=0;i<cnt;i++){
        for(int j=0;j<num[i].size();j++) printf("%d ",num[i][j]);
            printf("\n");
    }
}
double get_ans(){
    fm=1;
    int ccnt;
    double xishu,t_xishu;
    double s,ans=0;
    for(int i=0;i<cnt;i++)
        fm*=(int)(num[i].size()+1);
    for(int i=0;i<ll;i++){
        ccnt=0;t_xishu=1;
        for(int j=0;j<cnt;j++){
            if(num[j].size()>=i+1){
                right[ccnt]=(num[j].size()-i);
                t_val[ccnt++]=val[num[j][i]];
            }
            else t_xishu*=(double)(num[j].size()+1);
        }
        for(int j=1;j<(1<<ccnt);j++){
            xishu=1;s=0;
            int tj=j;
            for(int k=0;k<ccnt;k++){
                if(tj&1){
                    xishu*=right[k];
                    s+=t_val[k];
                }
                else xishu*=i+1;
                tj>>=1;
            }
            ans+=s*xishu*t_xishu;
            if(bit[j]>=2) ans+=s*xishu*t_xishu*bit[j]/ccnt;
        }
    }
    return ans/(fm-1);
}
void solve(){
    int n,m;
    int u,v;
    scanf("%d%d",&n,&m);
    init(n);
    for(int i=0;i<n;i++)
        scanf("%d",&val[i]);
    for(int i=0;i<m;i++){
        scanf("%d%d",&u,&v);
        addedge(u,v);
    }
    rebuild(n);
    double ans=get_ans();
    printf("%.3lf\n",ans);
}
int main()
{
    int _;
    scanf("%d",&_);
    getbit();
    while(_--) solve();
}
