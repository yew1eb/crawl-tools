//å ä¸ºæ¯ä¸ªä¸²çé¿åº¦ä¸è¶è¿5ï¼æå¤8ä¸ªä¸²ï¼æä»¥æç­å¬å±æ¯ä¸²æé¿ä¸º40ï¼æä»¥IDA*æç´¢ä¸è¶è¿40æ¬¡
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m,t;
char str[9][6],dna[5]= {'A','C','G','T'};
int len[9],tp[9];
bool dfs(int ps[],int ds,int depth)
{
    int i,j,k,ts[9];
    for(i=0; i<n; i++)
    {
        if(len[i]-ps[i]+ds>depth) return 0;
    }
    for(i=0; i<n; i++)
    {
        if(str[i][ps[i]]) break;
    }
    if(i==n) return 1;
    for(i=0; i<4; i++)
    {
        for(j=k=0; j<n; j++)
        {
            ts[j]=ps[j];
            if(dna[i]==str[j][ps[j]]) ts[j]+=1,k=1;
        }
        if(k)
            if(dfs(ts,ds+1,depth)) return 1;
    }
    return 0;
}
int main()
{
    int i,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=k=0; i<n; i++)
        {
            scanf("%s",str[i]);
            len[i]=strlen(str[i]);
        }
        memset(tp,0,sizeof(tp));
        while(!(dfs(tp,0,k)))
            k++;
        printf("%d\n",k);
    }
    return 0;
}