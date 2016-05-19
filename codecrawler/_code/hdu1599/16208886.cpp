#include<iostream>
using namespace std;
#define INF 100000000
#define min(a,b) a<b?a:b
#define MAX 105
int N,M,a,b,c;
int map[MAX][MAX],A[MAX][MAX];
int Floyd()
{
    int i,j,k;
    int min=INF;
    for(k=1;k<=N;k++)//æç­è·¯å¾å¤ä¸ç¹å°æç­è·¯é¦å°¾é¾æ¥,é£ä¹å°±å¾å°ä¸ä¸ªæå°ç¯
    {
        for(i=1;i<k;i++)
        {
            for(j=i+1;j<k;j++)
            {
                //æ±æå°ç¯ä¸è½ç¨ä¸¤ç¹é´æç­è·¯æ¾å¼,å ä¸º(i,k)ä¹é´çæç­è·¯,(k,j)ä¹é´çæç­è·¯å¯è½æéåçé¨å
                    //æä»¥map[][]å¶å®æ¯ä¸æ´æ°ç,è¿éååçº¯çfloydæç­è·¯ä¸ä¸æ ·
                    //A[i][j]ä¿å­çæ¯ i å° j çæç­è·¯æå¼å
                int tmp=A[i][j]+map[i][k]+map[k][j];
                if(tmp<min)
                    min=tmp;
            }
        }
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=N;j++)
            {
                if(A[i][j]>A[i][k]+A[k][j])
                    A[i][j]=A[i][k]+A[k][j];//A[][]ä¿å­ä¸¤ç¹é´æç­è·ç¦»
            }
        }
    }
    return min;
}
int main()
{
    int i,j;
    while(~scanf("%d%d",&N,&M))
    {
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=N;j++)
                map[i][j]=A[i][j]=INF;
        }
        for(i=1;i<=M;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            map[a][b]=map[b][a]=A[a][b]=A[b][a]=min(map[a][b],c);
        }
        int s=Floyd();
        if(s==INF)
            printf("It's impossible.\n");
        else
            printf("%d\n",s);
    }
    return 0;
}


