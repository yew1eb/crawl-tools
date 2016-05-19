#include"stdio.h"
#include"string.h"
int main()
{
    int flag[1001];              //1ä»£è¡¨å¯è§¦æ¸
    int num[1001];
    int prime[222],k;
    int i,l,temp;
    int T;
    int n;


    memset(num,0,sizeof(num));
    memset(flag,0,sizeof(flag));
    num[0]=num[1]=1;
    k=0;
    for(i=2;i<=1000;i++)
    {
        if(num[i]==0)
        {
            for(temp=2*i;temp<=1000;temp+=i)    num[temp]=1;
            flag[i+1]=1;            //1000è¯å®ä¸æ¯ç´ æ°ï¼æä»¥ä¸å¿å ä¸âif(i+1)<=1000âäºã
            prime[k]=i;
            k++;
        }
    }


    for(i=0;i<k;i++)
    for(l=i+1;l<k;l++)
    {
        if(prime[i]+prime[l]+1<=1000)    flag[prime[i]+prime[l]+1]=1;
        else    break;
    }


    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        if(flag[n]==0)    printf("yes\n");
        else            printf("no\n");
    }
    return 0;
}