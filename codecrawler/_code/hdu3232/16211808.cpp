#include<stdio.h>
int main()
{
    int n, i, cas = 0, d, p, l, v;
    while(~scanf("%d%d",&n,&d), n+d)
    {
        double ans = d*1.0;
        for(i = 0; i < n; i++)
        {
            scanf("%d%d%d",&p, &l, &v);
            ans -= l;  //åå»ä¸è¿è¿æ¡æ²³æ¶æç¨çæ¶é´
            ans += 2.0*l / v; //å ä¸è¿æ²³æ¶é´
        }
        printf("Case %d: %.3lf\n\n",++cas, ans);
    }
    return 0;
}