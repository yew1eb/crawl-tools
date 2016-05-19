#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define MAXN 10010
#define MAXM 100010

struct Edge
{
      int v, next;  
}edge[MAXM];    //è¾¹ç»ç¹æ°ç» 

int first[MAXN], stack[MAXN], DFN[MAXN], Low[MAXN], Belong[MAXM];
// first[]å¤´ç»ç¹æ°ç»,stack[]ä¸ºæ ,DFN[]ä¸ºæ·±ææ¬¡åºæ°ç»ï¼Belong[]ä¸ºæ¯ä¸ªç»ç¹æå¯¹åºçå¼ºè¿éåéæ å·æ°ç» 
// Low[u]ä¸ºuç»ç¹æèuçå­æ ç»ç¹æè½è¿½æº¯å°çææ©æ ä¸­ç»ç¹çæ¬¡åºå· 
int instack[10010];  // instack[]ä¸ºæ¯å¦å¨æ ä¸­çæ è®°æ°ç» 
int n, m, cnt, scnt, top, tot;

void init()
{
    cnt = 0;
    scnt = top = tot = 0;    //åå§åè¿éåéæ å·ï¼æ¬¡åºè®¡æ°å¨ï¼æ é¡¶æéä¸º0 
    memset(first, -1, sizeof(first));
    memset(DFN, 0, sizeof(DFN));   //ç»ç¹æç´¢çæ¬¡åºç¼å·æ°ç»ä¸º0ï¼åæ¶å¯ä»¥å½æ¯å¦è®¿é®çæ°ç»ä½¿ç¨ 
}

void read_graph(int u, int v) //æå»ºé»æ¥è¡¨ 
{
     edge[tot].v = v;
     edge[tot].next = first[u];
     first[u] = tot++;
}

void Tarjan(int v)       //Tarjanç®æ³æ±æåå¾çå¼ºè¿éåé 
{
     int min, t;
     DFN[v] = Low[v] = ++tot;    //cntä¸ºæ¶é´æ³
     instack[v] = 1;    //æ è®°å¨æ ä¸­ 
     stack[top++] = v;      //å¥æ  
     for(int e = first[v]; e != -1; e = edge[e].next)
     {   //æä¸¾vçæ¯ä¸æ¡è¾¹ 
           int j = edge[e].v;   //væé»æ¥çè¾¹ 
           if(!DFN[j])
           {   //æªè¢«è®¿é® 
               Tarjan(j);    //ç»§ç»­åä¸æ¾ 
               if(Low[v] > Low[j]) Low[v] = Low[j];  // æ´æ°ç»ç¹væè½å°è¾¾çæå°æ¬¡æ°å± 
           }
           else if(instack[j] && DFN[j] < Low[v])
           {   //å¦æjç»ç¹å¨æ å, 
               Low[v] = DFN[j];
           }
     }
     if(DFN[v] == Low[v])
     {     //å¦æèç¹væ¯å¼ºè¿éåéçæ ¹ 
           scnt++;   //è¿éåéæ å·å 1 
           do
           {
               t = stack[--top];   //éæ  
               instack[t] = 0;   //æ è®°ä¸å¨æ ä¸­ 
               Belong[t] = scnt;   //åºæ ç»ç¹tå±äºcntæ å·çå¼ºè¿éåé 
           }while(t != v);  //ç´å°å°vä»æ ä¸­éåº 
     }
}

void solve()
{
     for(int i = 1; i <= n; i++)   //æä¸¾æ¯ä¸ªç»ç¹ï¼æç´¢è¿éåé
        if(!DFN[i])  //æªè¢«è®¿é® 
           Tarjan(i);  //åæ¾iç»ç¹çè¿éåé 
}

int main()
{
    while(scanf("%d%d",&n,&m) && (n || m))
    {
        init();
        while(m--)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            read_graph(u, v);
        }
        solve();     //æ±å¼ºè¿éåé 
        if(scnt == 1) printf("Yes\n");  //åªæä¸ä¸ªå¼ºè¿éåéï¼è¯´ææ­¤å¾åä¸ªç»ç¹é½å¯è¾¾
        else printf("No\n");
    }
    return 0;
}