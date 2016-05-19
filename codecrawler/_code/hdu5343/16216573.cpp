#include<bits/stdc++.h> 
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
#define MAXN (90000*2+10)
#define Sigmasize (26) 
typedef unsigned long long ll;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+llabs(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
class SAM {
public:
    char s[MAXN];
    int n;
    SAM():n(0){MEM(s) MEM(son) MEM(pre) MEM(step) last=tot=0;}
    SAM(char *_s){n=strlen(_s),memcpy(s,_s,sizeof(char)*(n+5)); MEM(son) MEM(pre) MEM(step) last=tot=0;}
    void mem(){n=0; MEM(s) MEM(son) MEM(pre) MEM(step) last=tot=0;}
    void mem(char *_s){n=strlen(_s);memcpy(s,_s,sizeof(char)*(n+5)); MEM(son) MEM(pre) MEM(step) last=tot=0; MEM(g) MEM(sz) MEM(visit) }
    
    int son[MAXN][Sigmasize+1],pre[MAXN],step[MAXN],last,tot;
    
    void extend(char ch)
    {
        step[++tot]=step[last]+1;
        int p=last,np=tot;
        
        for(;!son[p][ch];p=pre[p]) son[p][ch]=np;
        if (!p) pre[np]=1;
        else {
            int q=son[p][ch];
            if (step[q]==step[p]+1) pre[np]=q;
            else {
                step[++tot]=step[p]+1;
                int nq=tot;
                memcpy(son[nq],son[q],sizeof(son[q]));
                pre[nq]=pre[q];
                pre[q]=pre[np]=nq;
                for(;son[p][ch]==q;p=pre[p]) son[p][ch]=nq;
            }
        }
        last=np;
    }
    
    void build(){
        last=tot=1;
        Rep(i,n) extend(s[i]-'a');
    }
    
    ll sz[MAXN];
    bool visit[MAXN];
    void dfs(int x)
    {
        visit[x]=1;
        Rep(ch,26) 
            if (son[x][ch]) 
            {
                if (!visit[son[x][ch]]) dfs(son[x][ch]);
                sz[x]+=sz[son[x][ch]];
            }
        sz[x]++;
    }
    
    ll g[MAXN][Sigmasize+1];
    void dfs2(int x)
    {

        visit[x]=1;
        bool flag=0;
        Rep(ch,26) 
            if (son[x][ch]) 
            {
                if (!visit[son[x][ch]]) dfs2(son[x][ch]);
                Rep(i,Sigmasize) g[x][i]+=g[son[x][ch]][i]; 
            } else if (!son[x][ch])
            {
                g[x][ch]++;
            }
        
    }
    
}S1,S2; 
char s1[MAXN],s2[MAXN];
ll res[MAXN];
int main()
{
//    freopen("A.in","r",stdin);
    
    int T;cin>>T;
    while(T--) {
        scanf("%s%s",s1,s2);
        S1.mem(s1),S2.mem(s2);
        S1.build();
        S2.build();
        S2.dfs(1);
        S1.dfs2(1);
        MEM(S1.visit);
        S1.dfs(1); 
        Rep(i,26) res[i]=S2.son[1][i]?S2.sz[S2.son[1][i]]:0;
        ll ans=0;
//        Rep(i,26) cout<<S1.g[1][i]<<' ';cout<<endl;
//        Rep(i,26) cout<<res [i]<<' ';
        
        Rep(i,26) ans+=res[i]*S1.g[1][i];
        cout<<ans+S1.sz[1]<<endl;
        
        
    }
    
    return 0;
}
