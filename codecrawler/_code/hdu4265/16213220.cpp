#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cmath>
#include<cctype>
#include<ctime>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=next[p])
#define Lson (x<<1)
#define Rson ((x<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define F (100000007)
#define MAXn (80+10)
#define MAXN (500+19)
#define MAXM (69999+100)
long long mul(long long a,long long b){return (a*b)%F;}
long long add(long long a,long long b){return (a+b)%F;}
long long sub(long long a,long long b){return (a-b+(a-b)/F*F+F)%F;}
typedef long long ll;
class Max_flow  //dinic+å½åå¼§ä¼å   
{    
public:    
    int n,s,t;    
    int q[MAXN];    
    int edge[MAXM],next[MAXM],pre[MAXN],weight[MAXM],size;    
    void addedge(int u,int v,int w)      
    {      
        edge[++size]=v;      
        weight[size]=w;      
        next[size]=pre[u];      
        pre[u]=size;      
    }      
    void addedge2(int u,int v,int w){addedge(u,v,w),addedge(v,u,0);}     
    bool b[MAXN];    
    int d[MAXN];    
    bool SPFA(int s,int t)      
    {      
        For(i,n) d[i]=INF;    
        MEM(b)    
        d[q[1]=s]=0;b[s]=1;      
        int head=1,tail=1;      
        while (head<=tail)      
        {      
            int now=q[head++];      
            Forp(now)      
            {      
                int &v=edge[p];      
                if (weight[p]&&!b[v])      
                {      
                    d[v]=d[now]+1;      
                    b[v]=1,q[++tail]=v;      
                }      
            }          
        }      
        return b[t];      
    }     
    int iter[MAXN];  
    int dfs(int x,int f)  
    {  
        if (x==t) return f;  
        Forpiter(x)  
        {  
            int v=edge[p];  
            if (weight[p]&&d[x]<d[v])  
            {  
                  int nowflow=dfs(v,min(weight[p],f));  
                  if (nowflow)  
                  {  
                    weight[p]-=nowflow;  
                    weight[p^1]+=nowflow;  
                    return nowflow;  
                  }  
            }  
        }  
        return 0;  
    }  
    int max_flow(int s,int t)  
    {  
        int flow=0;  
        while(SPFA(s,t))  
        {  
            For(i,n) iter[i]=pre[i];  
            int f;  
            while (f=dfs(s,INF))  
                flow+=f;   
        }  
        return flow;  
    }   
    void mem(int n,int s,int t)    
    {    
        (*this).n=n;  
        (*this).t=t;    
        (*this).s=s;    
          
        size=1;    
        MEM(pre)   
    }    
}S;    

char s[MAXn][MAXn];
int n;
bool check(int m)
{
    S.mem(2*n+2,1,2*n+2);
    For(i,n) S.addedge2(1,i+1,m),S.addedge2(n+1+i,2*n+2,m);
    For(i,n) For(j,n) if (s[i][j]=='Y') S.addedge2(1+i,n+1+j,1);

    if (S.max_flow(1,2*n+2)==n*m) return 1;
    return 0;
}

int Ans[MAXn];

int main()
{
//    freopen("hdu4265.in","r",stdin);
//    freopen(".out","w",stdout);
    
    while(scanf("%d",&n)==1)
    {
        if (!n) break;
        For(i,n) scanf("%s",s[i]+1);
        
        int l=0,r=n,ans=0;
        while(l<=r)
        {
            int m=(l+r)>>1;
            if (check(m)) ans=m,l=m+1;
            else r=m-1;
        }
        
        check(ans);
            
        printf("%d\n",ans);
        Fork(i,2,n+1)
        {
            for(int p=S.pre[i];p;p=S.next[p])
                if (!S.weight[p^1]&&S.edge[p]>n+1) s[i-1][S.edge[p]-n-1]='N'; 
            
        }
    
        while (ans--)
        {
            S.mem(2*n+2,1,2*n+2);
            For(i,n) S.addedge2(1,i+1,1),S.addedge2(n+1+i,2*n+2,1);
            For(i,n) For(j,n) if (s[i][j]=='Y') S.addedge2(1+i,n+1+j,1);
            S.max_flow(1,2*n+2);
            
        
            
            Fork(i,2,n+1)
            {
                for(int p=S.pre[i];p;p=S.next[p])
                    if (!S.weight[p]&&S.edge[p]>n+1)
                    {
                        Ans[S.edge[p]-n-1]=i-1,s[i-1][S.edge[p]-n-1]='N'; 
                        break;
                    }
            }
            
            For(i,n-1) printf("%d ",Ans[i]);printf("%d\n",Ans[n]);
    
            
        }    
        
    }
    
    return 0;
}
