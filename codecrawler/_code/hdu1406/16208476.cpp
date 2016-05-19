#include<cstdio>
const int MAXN=10000+2;
const int N=MAXN>>1;
int sum[MAXN]={0};
int main()
{
    for(int i=2;i<N;i++)
        for(int k=i+i;k<MAXN;k+=i)
            sum[k]+=i;

    int T;
    scanf("%d",&T);
    int a,b;
    while(T--)
    {
        scanf("%d%d",&a,&b);
        if(a>b)
        {
            int temp=a;
            a=b;
            b=temp;
        }
        int cnt=0;
        for(int i=a;i<=b;i++)
        {
            if(sum[i]==i-1)    //å ä¸ºææ°ç»ä¸å¼å§é½æ¯0ï¼èå å­åå«1
                cnt++;
        }

        printf("%d\n",cnt);
    }
    return 0;

}