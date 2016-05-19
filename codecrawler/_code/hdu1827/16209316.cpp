#include<cstdio>
#include<cstring>
#include<stack>
#include<climits>
using namespace std;

const int N = 1001;

struct Edge{
    int s,e,next;
}edge1[2*N],edge2[2*N];

int n,m,e_num1,e_num2,vis_num,cnt;
int head[N],tim[N],low[N],instack[N],belong[N],price[N],de[N];

void AddEdge(int a,int b,Edge edge[],int &e_num){
    edge[e_num].s=a; edge[e_num].e=b; edge[e_num].next=head[a]; head[a]=e_num++;
}

void getmap(){
    int i,a,b;
    for(i=1;i<=n;i++)
        scanf("%d",&price[i]);
    e_num1=0;
    memset(head,-1,sizeof(head));
    while(m--){
        scanf("%d%d",&a,&b); 
        AddEdge(a,b,edge1,e_num1);
    }
}

stack <int> st;
void tarjan(int x){//æ³¨æè¿æ¯ä¸ªéå½è¿ç¨
    int i,j;
    tim[x]=low[x]=++vis_num;//timæ¯æ¶é´æ³,æ è®°è¯¥ç¹åºç°çæ¶é´,lowæ¯è¯¥ç¹è½å°è¾¾çç¹ä¸­æ¶é´æ³å¼çæå°å¼
    st.push(x);
    instack[x]=1;
    for(i=head[x];i!=-1;i=edge1[i].next){
        int u=edge1[i].e;
        if(tim[u]==-1){//æ¶é´æ³ä¸º-1,ä¹å°±æ¯æ²¡æè®¿é®è¿
            tarjan(u);
            if(low[x]>low[u])low[x]=low[u];//æ´æ°lowå¼,åè½å°è¾¾çæä¸(å°)ä½ç½®
        }
        //ç¹uå·²ç»è®¿é®è¿ä¸å¨æ ä¸­,æ¶é´æ³æ¯ç¹iå°,é£ä¹lowå¼å½ç¶æ¯ç¹iå°
        //(å ä¸ºtim,lowé½åå§åä¸ºvis_num),é£ä¹low[i]å¯ä»¥æ´æ°
        else if(instack[u] && tim[u]<low[x])
            low[x]=tim[u];
    }
    if(tim[x]==low[x]){
        cnt++;
        do{//éæ ,ç´å°çå°æ ¹ä¸ºæ­¢
            j=st.top();
            st.pop();
            instack[j]=0;
            belong[j]=cnt;//æ è®°è¯¥ç¹æå±åéçæ å·
        }while(j!=x);
    }
}

int fun(int x){
    int i,min=INT_MAX;
    for(i=1;i<=n;i++){
        if(belong[i]==x && price[i]<min)
            min=price[i];
    }
    return min;
}

void solve(){
    int i;
    cnt=vis_num=0;
    memset(tim,-1,sizeof(tim));
    memset(low,0,sizeof(low));
    memset(instack,0,sizeof(instack));
    for(i=1;i<=n;i++){
        if(tim[i]==-1)tarjan(i);
    }
    
    e_num2=0;
    memset(head,-1,sizeof(head));
    memset(de,0,sizeof(de));
    for(i=0;i<e_num1;i++){
        int j=edge1[i].s;
        int k=edge1[i].e;
        if(belong[j] != belong[k]){
            AddEdge(belong[j],belong[k],edge2,e_num2);
            de[belong[k]]++;
        }
    }
    int sum=0,count=0;
    for(i=1;i<=cnt;i++){
        if(de[i]==0){
            sum+=fun(i);count++;
        }
    }
    printf("%d %d\n",count,sum);
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        getmap();
        solve();
    }
    return 0;
}