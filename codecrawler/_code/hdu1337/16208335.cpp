#include<stdio.h>
#include<string.h>
int main()
{
    int t,x[105],n;
    scanf("%d",&t);
    while(t--)
    {
        memset(x,0,sizeof(x));
        scanf("%d",&n);
        for(int i=1;i<=n;++i)//å¤å°æ¬¡æä½
        {
            for(int j=2;j*i<=n;++j)//å¯¹åºæä½çé¨çç¼å·.
            {
                x[i*j]=!x[i*j];
            }
        }
        int cnt=0;
        for(int i=1;i<=n;++i)//æ¥æ¾ç»è®¡....
        {
            if(!x[i])
            {
                ++cnt;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}