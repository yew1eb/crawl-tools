#include<cstdio>
#include<cstring>
#include<STACK>
#include<climits>
using namespace std;

const int N = 20010;

struct Edge{
    int s,e,next;
}edge[3*N];

int n,m,e_num,vis_num,cnt,head[N],instack[N],low[N],tim[N],belong[N];

void AddEdge(int a,int b){
    edge[e_num].s=a; edge[e_num].e=b; edge[e_num].next=head[a]; head[a]=e_num++;
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

void init(){
    vis_num=cnt=0;
    memset(instack,0,sizeof(instack));
    memset(belong,-1,sizeof(belong));
    memset(tim,-1,sizeof(tim));
    memset(low,0,sizeof(low));
}

int main()
{
    int t,i,left,right,mid,ans;
    int a[N],b[N],c[N];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++)
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
        left=0; right=m;
        while(left<=right){
            mid=(left+right)/2;
            e_num=0;
            memset(head,-1,sizeof(head));
            for(i=0;i<mid;i++){
                if(c[i]==0){//x[ a[i] ],x[ b[i] ]ä¸è½åæ¶ä¸º0
                    AddEdge(2*a[i],2*b[i]+1);
                    AddEdge(2*b[i],2*a[i]+1);
                }
                else if(c[i]==1){//x[ a[i] ],x[ b[i] ]ä¸è½ä¸å
                    AddEdge(2*a[i],2*b[i]);
                    AddEdge(2*a[i]+1,2*b[i]+1);

                    AddEdge(2*b[i],2*a[i]);
                    AddEdge(2*b[i]+1,2*a[i]+1);
                }
                else{//x[ a[i] ],x[ b[i] ]ä¸è½åæ¶ä¸º1
                    AddEdge(2*a[i]+1,2*b[i]);
                    AddEdge(2*b[i]+1,2*a[i]);
                }
            }
            init();
            for(i=0;i<2*mid;i++){
                if(tim[i]==-1)tarjan(i);
            }
            int flag=1;
            for(i=0;i<mid;i++){
                if(belong[2*i]==belong[2*i+1]){
                    flag=0;break;
                }
            }
            if(flag){
                ans=mid; left=mid+1;
            }
            else right=mid-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}