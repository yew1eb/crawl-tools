#include<cstdio>
#include<cmath>
int main()
{
    int x,y,flag = 0;
    while(scanf("%d%d",&x,&y),x||y)
    {

        flag = 1;
        for(int i = x;i<=y;++i)
        {
            int t = i*i+i+41,j;
            for(j = 2;j <= int(sqrt(t));++j)
                if(t%j == 0)
                {
                    flag = 0;
                    break;
                }
            if(flag == 0)break;

        }
        if(!flag)
            printf("Sorry\n");
        else
            printf("OK\n");

    }
    return 0;
}
