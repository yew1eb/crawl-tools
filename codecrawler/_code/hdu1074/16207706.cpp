#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int Max=1<<16;
struct node
{
    int time; //è¯¥ç¶æçæ¶é´
    int pre; //åä¸ç¶æ
    int cost; //æå°çæå¤±
}dp[Max];
struct course
{
    int deadtime; //æªæ­¢æ¥æ
    int cost; //æéæ¶é´
    char name[201];
}course[16];
int visit[Max];
void print(int status)
{
    int cur,num;
    cur=dp[status].pre^status; //ååçè¯¾ç¨
    num=0;
    cur>>=1;
    while(cur)
    {
        num++;
        cur>>=1;
    }
    if(dp[status].pre!=0)
    print(dp[status].pre);
    printf("%s\n",course[num].name);
}
int main()
{
    int i,n,t;
    int upper,work,cur,k,reduce;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        upper=(1<<n)-1;//æå¤§çç¶æ
        for(i=0;i<n;i++)
        scanf("%s%d%d",&course[i].name,&course[i].deadtime,&course[i].cost);
        memset(visit,0,sizeof(visit));
        dp[0].time=0;  //åå§å
        dp[0].pre=-1;
        dp[0].cost=0;
        visit[0]=1;
        for(i=0;i<upper;i++)
        {
            for(work=0;work<n;work++)
            {
                cur=1<<work;
                if((cur&i)==0)  //è¯¥é¡¹è¯¾ç¨è¿æªå
                {
                    k=cur|i;//ä¸ä¸ç¶æ
                    dp[k].time=dp[i].time+course[work].cost;
                    reduce=dp[k].time-course[work].deadtime;
                    if(reduce<0)
                    reduce=0;
                    reduce+=dp[i].cost;
                    if(visit[k]) //è¯¥ç¶æå·²æ è®° 
                    {
                        if(reduce<dp[k].cost)
                        {
                            dp[k].cost=reduce;
                            dp[k].pre=i;
                        }
                        else if(reduce==dp[k].cost)
                        {
                            if(dp[k].pre>i)
                            dp[k].pre=i;
                        }
                    }
                    else
                    {
                        visit[k]=1;
                        dp[k].cost=reduce;
                        dp[k].pre=i;
                    }
                }
            }
        }
        printf("%d\n",dp[upper].cost);
        print(upper);//éå½è¾åº 
    }
    return 0;
}
