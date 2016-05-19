#include<iostream>
#include<string.h>
#include<vector>
#define max 10010
using namespace std;

vector <int> vec[max];
int in[max], stack[max] , block[max];
int low[max], dfn[max];
int top , ans1, ans2 ,step;
int n, m;

void init()
{
    for(int i=0;i<max;i++)  
    {
        low[i]=dfn[i]=stack[i]=0;
        vec[i].clear();
    }
    top=-1 ; step=ans1=ans2=0;
}
void insert(int u, int v)
{
    vec[u].push_back(v);
    vec[v].push_back(u);
}
void deal_circle()
{//cout<<block[0]<<endl<<endl;
    int num=0; 
    for(int i=1;i<=block[0];i++)
    {//cout<<block[i]<<endl;
        for(int j=0;j<vec[block[i]].size();j++)
        {
            int v=vec[block[i]][j];  
            if(in[v]) { num++; } //å¦ævå±äºå½ååï¼åå°è¾¹æ°ç´¯å ä¸æ¬¡ 
        }
    }
    num/=2;//å ä¸ºæ¯æ¡è¾¹çé¡¶ç¹æä¸¤ä¸ªï¼ä¸é½å±äºè¯¥åä¸­ï¼æä»¥æ¯æ¡è¾¹è¢«éå¤è®¡ç®äºä¸æ¬¡ 
    if(block[0]>num)  ans1+=num;
    else if(block[0]<num) ans2+=num;
    //cout<<"ans1= "<<ans1<<"   ans2= "<<ans2<<endl;
}
void tarjan(int u )
{
     int v;
     dfn[u]=low[u]=++step;
     stack[++top]=u;
     for(int i=0;i<vec[u].size(); i++)
     {
         v=vec[u][i]; 
         if(!dfn[v])   //è¥è¯¥ç¹æ²¡æè¢«è®¿é®è¿ 
         {
             tarjan(v);
             low[u]=min(low[u], low[v]);
             if(low[v]>=dfn[u]) //è¯´æuçå­èç¹æ²¡æä¸uçç¥åç¸è¿çååè¾¹ï¼å³uä¸ºå²é¡¹ 
             {
                 block[0]=0;    //cout<<endl<<endl;
                 memset(in,0,sizeof(in));
                 int t;
                 do
                 {
                    t=stack[top--];
                    block[++block[0]]=t;
                    in[t]=1;  //cout<<u<<"-----"<<t<<endl;
                 }while(v!=t);
                 block[++block[0]]=u; in[u]=1;
                 deal_circle();
             }
         }
         else
         low[u]=min(dfn[v] , low[u]);
     }
}

int main()
{
    int a, b;
    while(~scanf("%d%d",&n,&m) && n+m )
    {
        init();
        for(int i=0;i<m;i++)
        {
           scanf("%d%d",&a,&b);
           insert(a,b);
        }
        for(int i=0;i<n;i++)
        if(!dfn[i])  tarjan(i);
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}