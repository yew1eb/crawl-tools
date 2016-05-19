#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
#define maxn 1111*4
vector<int>g[maxn];  
stack<int>st;  
int n,m,scc,index;  
int low[maxn],dfn[maxn],instack[maxn],fa[maxn];  
int key1[maxn],key2[maxn];
int door1[maxn],door2[maxn];
void init()//åå§å  
{  
    scc=index=0;  
    while(!st.empty())st.pop();  
    for(int i=0;i<maxn;i++)g[i].clear();  
    memset(dfn,0,sizeof(dfn));  
    memset(low,0,sizeof(low)); 
    memset(instack,0,sizeof(instack));  
}  
void tarjan(int u)//æ±å¼ºèéåé  
{  
    dfn[u]=low[u]=++index;  
    instack[u]=1;  
    st.push(u);  
    int v,size=g[u].size();  
    for(int i=0;i<size;i++)  
    {  
        v=g[u][i];  
        if(!dfn[v])  
        {  
            tarjan(v);  
            low[u]=min(low[u],low[v]);  
        }  
        else if(instack[v]) 
            low[u]=min(low[u],dfn[v]);  
    }  
    if(dfn[u]==low[u])  
    {  
        scc++;  
        do  
        {  
            v=st.top();  
            st.pop();  
            fa[v]=scc;  
            instack[v]=0;  
        }while(v!=u);  
    }  
}  
void build(double mid)  
{  
    for(int i=1;i<=n;i++)//å¯¹ææçé¥åå³ç³»å»ºè¾¹ 
    {
        g[key1[i]*2].push_back(key2[i]*2+1);
        g[key2[i]*2].push_back(key1[i]*2+1);
    }
    for(int i=1;i<=mid;i++)//å¯¹è¦å¼çé¨çå³ç³»å»ºè¾¹ 
    {
        g[door1[i]*2+1].push_back(door2[i]*2);
        g[door2[i]*2+1].push_back(door1[i]*2);
    }
}  
bool check()//å¤æ­æ¯å¦å­å¨ä½¿å¾å¸å°å¬å¼å¼ä¸ºççä¸ç»å¸å°åéèµå¼ 
{  
    for(int i=0;i<2*n*2;i++)//æ±å¼ºèéåé 
        if(!dfn[i]) 
            tarjan(i);  
    for(int i=0;i<2*n;i++)  
        if(fa[2*i]==fa[2*i+1])//çç¾ 
            return false;  
    return true;  
}  
int main()
{
    while(scanf("%d%d",&n,&m),n||m)
    {
        for(int i=1;i<=n;i++)
            scanf("%d%d",&key1[i],&key2[i]);
        for(int i=1;i<=m;i++)
            scanf("%d%d",&door1[i],&door2[i]);
        int left=0,right=m,ans=0;
        while(left<=right)//äºåå±æ°,ç¨ansè®°å½ç­æ¡ 
        {
            int mid=(left+right)/2;
            init();
            build(mid);
            if(check())
            {
                ans=max(ans,mid);
                left=mid+1;
            }
            else
                right=mid-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}