#include <stdio.h>

struct Milk
{
    char name[1000];
    int p,v;
} milk[100000];

int main()
{
    int t,i,flag,n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&t);
        double m = 0;
        for(i = 0; i<t; i++)
        {
            scanf("%s%d%d",milk[i].name,&milk[i].p,&milk[i].v);
            int cnt = 0;
            if(milk[i].v < 200)
                continue;
            while(1)
            {
                milk[i].v-=200;
                cnt++;
                if(cnt == 5)
                    break;
                if(milk[i].v <200)
                    break;
            }
            double k = (double)cnt/milk[i].p;//æ§ä»·æ¯
            if(k >= m)
            {
                if(k > m )//åæ§ä»·æ¯æå¤§ç
                {
                    m = k;
                    flag = i;
                }
                if(k == m)
                {
                    if(milk[i].p < milk[flag].p)//æ§ä»·æ¯ä¸æ ·åä¾¿å®ç
                        flag = i;
                    else if(milk[i].p == milk[flag].p)//ä»·æ ¼ä¹ä¸æ ·åå®¹éå¤§ç
                    {
                        if(milk[i].v > milk[flag].v)
                            flag = i;
                    }
                }
            }
        }
        printf("%s\n",milk[flag].name);
    }

    return 0;
}
