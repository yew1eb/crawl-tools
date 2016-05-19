#include<cstdio>
#include<cstring>
#include<stack>
#include<climits>
using namespace std;

const int N = 2010;
struct Edge{
    int s,e,next;
}edge[1000010];

int n,e_num,vis_num,cnt,head[N],instack[N],low[N],tim[N],belong[N];

void AddEdge(int a,int b){
    edge[e_num].s=a; edge[e_num].e=b;
    edge[e_num].next=head[a]; head[a]=e_num++;
}

void getmap()
{
    int m,a,b,c,d;
    scanf("%d",&m);
    e_num=0;
    memset(head,-1,sizeof(head));
    while(m--){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        AddEdge(2*a+c,2*b+(1-d));
        AddEdge(2*b+d,2*a+(1-c));
    }
}

stack <int>st;
void tarjan(int x){
    int i;
    tim[x]=low[x]=++vis_num;
    instack[x]=1;
    st.push(x);
    for(i=head[x];i!=-1;i=edge[i].next){
        int u=edge[i].e;
        if(tim[u]==-1){
            tarjan(u);
            if(low[x]>low[u])low[x]=low[u];
        }
        else if(instack[u] && low[x]>tim[u])low[x]=tim[u];
    }
    if(low[x]==tim[x]){
        cnt++;
        do{
            i=st.top();
            st.pop();
            instack[i]=0;
            belong[i]=cnt;
        }while(i!=x);
    }
}

void solve(){
    int i;
    vis_num=cnt=0;
    memset(instack,0,sizeof(instack));
    memset(belong,-1,sizeof(belong));
    memset(tim,-1,sizeof(tim));
    memset(low,0,sizeof(low));
    for(i=0;i<2*n;i++){
        if(tim[i]==-1)tarjan(i);
    }

    int flag=1;
    for(i=0;i<n;i++){
        if(belong[2*i]==belong[2*i+1]){
            flag=0;break;
        }
    }
    printf(flag?"YES\n":"NO\n");
}

int main()
{
    while(~scanf("%d",&n))
    {
        getmap();
        solve();
    }
    return 0;
}