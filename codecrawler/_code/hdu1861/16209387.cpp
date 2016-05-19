#include<stdio.h>
#include<string.h>
struct boat
{
    int time;
    int flag;
}a[105];
int count; /*è®°å½æ¬¡æ°*/
double sum; /*è®°å½æ¶é´*/
int main()
{
    int num,h,m;
    char c;
    sum=0; 
    count=0;
    memset(a,0,sizeof(a)); /*åå§å*/
    while(1)
    {
        scanf("%d",&num); /*è¹å·*/
        if(num==-1)
            break;
        getchar();  /*å¸æ¶ç©ºæ ¼*/
        scanf("%c",&c); /*ç§è¹ç¶æ*/
        scanf("%d:%d",&h,&m);
        if(num==0) /*ä¸å¤©ç§è¹å·¥ä½ç»æ*/
        {
            if(count) 
                printf("%d %.lf\n",count,sum/count); /*è¾åºæ¶ç»æåèäºå¥*/
            else
                printf("0 0\n");
            sum=0;
            count=0;
            continue;
        }
        if(c=='S')
        {
            a[num].time=h*60+m;
            a[num].flag=1;
        }
        else
        {
            if(a[num].flag) /*å¤æ­è¿æ¡è¹æ¯å¦ç§åºå»äº*/
            {
                sum+=h*60+m-a[num].time;  /*æ±åºç§è¹æ»æ¶é´*/
                count++;  /*æ¬¡æ°*/
                a[num].flag=0; /*æ è®°è¹å·²å½è¿*/
            }
        }
    }
    return 0;
}