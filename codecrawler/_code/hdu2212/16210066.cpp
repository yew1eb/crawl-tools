#include<stdio.h>
int f[15],an;
int pass(unsigned int sum)//å¤æ­æ¯ä¸ä½çä»å±åæ¯ä¸æ¯ç­äºæ¬èº«ï¼ååæ¯å ä½æ°
{
    unsigned int su=0,a=sum;
    int k,t=0;
    while(a>0)
    {
        k=a%10;
        su+=f[k];
        a/=10;
        t++;
    }
    return (su==sum)?t:0;
}
void DFS(unsigned int sum,int k,int t)//kæ¯sumè¦è¾¾å°å¤å°ä½æ°ï¼tæ¯å½åçæ°æ¯å ä½æ°
{
    int e;
    if(pass(sum)==k)//åªæå½ååçä½æ°ç­è¦æ±çä½æ°æè¾åºï¼ä¸ç¶ä¼éå¤
    printf("%d\n",sum);

    if(t<k)//å½åçä½æ°è¾¾ä¸å°è¦æ±çä½æ°æç»§ç»­å 
    for(e=0;e<10;e++)
    if((e!=0||t!=0)&&sum*10+e<=2147483647)//(e!=0||t!=0)æ¯æ§å¶æé«ä½ä¸ä¸º0
    {
        DFS(sum*10+e,k,t+1);
    }
}
int main()
{
    int i;
    f[0]=1;
    for(i=1;i<10;i++)
    f[i]=f[i-1]*i;

    for(i=1;i<6;i++)
    DFS(0,i,0);
}
