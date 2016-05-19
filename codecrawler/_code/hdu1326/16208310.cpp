#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int n,cas = 1;
    while(~scanf("%d",&n),n)
    {
        int a[100],i,sub = 0;
        for(i = 0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sub+=a[i];
        }
        sub = sub/n;
        sort(a,a+n);
        int sum = 0;
        printf("Set #%d\nThe minimum number of moves is ",cas++);
        while(a[n-1]>sub)
        {
            if(a[n-1]-sub>sub - a[0])//æå¤§çè¾¾å°å¹³åå¼æ¶å¤åºçæ¯æå°çæ¬ ç¼ºçå¤ï¼æå°çè¡¥æ»¡ï¼å¤§çç»è®¡å©ä½ç
            {
                sum+=sub-a[0];
                a[n-1] = a[n-1] - (sub-a[0]);
            }
            else if(a[n-1]-sub == sub - a[0])//ç¸ç­åä¸¤ä¸¤è¡¥æ»¡
            {
                sum+=a[n-1]-sub;
                a[n-1] = sub;
                a[0] = sub;
            }
            else//å°äºï¼ååææå¤§çåæå¹³åï¼å¤åºçç§»å°æå°
            {
                sum += a[n-1] - sub;
                a[n-1] = sub;
                a[0] = a[0] + a[n-1] - sub;
            }
            sort(a,a+n);//æ¯æ¬¡é½æåºä¸æ¬¡
        }
        printf("%d.\n\n",sum);
    }

    return 0;
}
