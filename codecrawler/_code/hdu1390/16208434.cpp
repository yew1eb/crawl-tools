#include<stdio.h>
#include<string.h>
int ans[110];
int main()
{
    int N,T;
    scanf("%d",&T);
    while(T--)
    {
        memset(ans,0,sizeof(ans));
        scanf("%d",&N);
        int num = 0,count = 0;
        while(N)
        {
            if(N&1)
            {
                ans[num++] = count;
                count++;
            }
            else
            {
                count++;
            }
            N >>= 1;
        }
        for(int i = 0; i < num; i++)
        {
            if(i!=num-1)
                printf("%d ",ans[i]);
            else
                printf("%d\n",ans[i]);
        }
    }

    return 0;
}
