//çäºæè·¯ï¼è¿æ²¡æçä»£ç ï¼è¯´æ¯ä»ä¹æå°å²ï¼æ æºæ æ±å¯è¡æµ
//è¾å¥u,v,d,bï¼dæï¼d+bæï¼så°tï¼é½è¦çæ¹å,xä¸ºdåï¼yä¸ºd+båï¼è¦æ¾x>yï¼é¦åtéååªæä¸ä¸ªåç´ ï¼
//å ä¸ºå¦ææä¸¤ä¸ªï¼è·èµ°ä¸ä¸ªåyåå°ï¼æ³¨æsåtäºä¸ºè¡¥é ,å¤§æ°´é¢ï¼ææ¨ççæè·¯å°±è¡äº ï¼éå¨æè 
#include<iostream>
#include<cstring>
#define ll __int64
using namespace std;
struct node
{
    ll wo;ll di;
}map[205][205];//å¼å¾ç¨å¾®å¤§ä¸ç¹ï¼ä¸ç¶ä¼REï¼å ä¸10å·¦å³å§ 
int n,m;
bool solve()
{
    
    for(int i=1;i<=n;i++)//æxå°½å¯è½çæ¾è¿å»ï¼è®©xå°½å¯è½å¤§ 
    {
       ll sset=0;ll tset=0;
       for(int j=1;j<=n;j++)
       {
           
           
               sset+=map[j][i].wo;
            tset+=map[i][j].di; 
           
       } 
       //cout<<sset<<" "<<tset<<endl;
       if(sset>tset)
       return false;
        
    }
    return true;
}

int main()
{
    int CAS;
    scanf("%d",&CAS);
    for(int kcas=1;kcas<=CAS;kcas++)
    {
        for(int i=1;i<=202;i++)
        for(int j=1;j<=202;j++)
        {
            map[i][j].wo=0;map[i][j].di=0;
        } 
        scanf("%d%d",&n,&m);
        int u,v;ll d,b;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%I64d%I64d",&u,&v,&d,&b);
            map[u][v].wo=d;
            map[u][v].di=d+b;
        }
        if(solve())
        printf("Case #%d: happy\n",kcas);
        else
        printf("Case #%d: unhappy\n",kcas);
    
    } 
    return 0;
} 