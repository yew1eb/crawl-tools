#include <stdio.h>

int main()
{
    double h,u,d,f;
    double start_h,pa_h,sum_h,xiahua_h,t;
    int day = 0;
    /*
    start_h:å¼å§éåº¦
    pa_hï¼æ­¤æ¬¡ç¬åé«åº¦
    sum_hï¼æ²¡ä¸æ»æ¶çé«åº¦
    xiahua_hï¼ä¸æ»åçé«åº¦
    */
    while(~scanf("%lf%lf%lf%lf",&h,&u,&d,&f))
    {
        if(!h)
        break;
        f = f/100;
        t = u*f;
        start_h = pa_h = sum_h = xiahua_h = 0;
        day = 0;
        int flag = 1;
        while(sum_h<=h)
        {
            pa_h = u;
            sum_h = start_h + pa_h;;
            xiahua_h = sum_h-d;
            start_h = xiahua_h;
            u-=t;
            if(u<=0)
            {
                u = 0;
                t = 0;
            }
            day++;
            if(xiahua_h<0)
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        printf("success on day %d\n",day);
        else
        printf("failure on day %d\n",day);
    }

    return 0;
}
