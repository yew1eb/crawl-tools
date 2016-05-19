#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int line[25];//è®°å½è·¯å¾ã
int map[25][25];//è®°å½åå¸æ¯å¦ç¸é»ã
int a,b,c;
int star[1000];//è®°å½å¶å®åå¸ã
int judge[25];//æ è®°å·²ç»èµ°è¿çåå¸ã
int num,date;
void output()//è¾åºã
{
    printf("%d:  ",date++);
    for(int i=0;i<20;i++)
    {
        printf("%d ",line[i]);
    }
    printf("%d\n",line[0]);
    return;
}
void dfs(int s,int step)//åå«è¡¨ç¤ºç°å¨æå¨çåå¸ä»¥åå°è¾¾è¿ä¸ªåå¸çæ­¥æ°ãç®æ³ä¸»ä½è¿æ¯è®ç®åçã
{
    if(step==19)
    {
        if(map[s][line[0]]==1)
        {
            output();
        }
        return;
    }
    for(int i=1;i<=20;i++)
    {
        if(judge[i]==0&&map[s][i]==1)
        {
            judge[i]=1;
            line[step+1]=i;
            dfs(i,step+1);
            judge[i]=0;
        }
    }
    return;
}
int main()
{
    memset(map,0,sizeof(map));//åå§åã
    for(int i=1;i<=20;i++)//æ³¨æiçåå§å¼
    {
        scanf("%d%d%d",&a,&b,&c);
        map[i][a]=1;
        map[i][b]=1;
        map[i][c]=1;
    }
    for(int i=0;;i++)
    {
        scanf("%d",&star[i]);
        if(star[i]==0)
        {
            num=i;//è®°å½èµ·ç¹çä¸ªæ°ã
            break;
        }
    }
    date=1;
    for(int i=0;i<num;i++)
    {
        memset(line,0,sizeof(line));
        memset(judge,0,sizeof(judge));//è¿ä¸¤ä¸ªåå§åä¸å®è¦è®°å¾ã
        judge[star[i]]=1;
        line[0]=star[i];
        //ss=star[i];
        dfs(star[i],0);
    }
    return 0;
}
