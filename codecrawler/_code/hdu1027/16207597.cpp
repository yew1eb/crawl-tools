#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k,n,m,t;
    int f[9]={0,1,1,2,6,24,120,720,5040};
    int num[9],store[8];
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        i=j=8,k=t=0,m=m-1;
        memset(num,0,sizeof(num));
        while(m)//è·ånumæ°ç»
        {
            if(m>=f[i])
            {
                m-=f[i];
                num[i]+=1;
            }else
            {
                i--;
            }
        }
        while(j&&!num[j])//å¾å°ä»åªä¸ä½å¼å§æ¹å
        {
            j--;
        }
        for(i=0;i<j;i++)
        {
            store[i]=n-j+1+i;//æ¹åçæåjä¸ªæ°å­
        }
        for(i=1;i<=n-j;i++)
            printf("%d ",i);
        for(k=j;k>1;k--)
        {
            printf("%d ",store[t+num[k]]);
            for(i=t+num[k];i>t;i--)
                store[i]=store[i-1];//æ¯éä¸æ¬¡å°±æä¸æ¬¡æ°ç»
            t++;
        }
        printf("%d\n",store[t+num[k]]);
    }
    return  0; 
}