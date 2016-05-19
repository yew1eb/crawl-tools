#include<stdio.h>  
int main()  
{  
    int i,n,sum,h,m,s,flag,t;  
    char str[500];  
    float d;  
    scanf("%d%f",&n,&d);  
    while(~scanf("%d",&t))  
    {  
        flag=1,sum=0;  
        for(i=0;i<n&&flag;i++)  
        {  
            if(scanf("%d:%d:%d",&h,&m,&s)==3)  
                sum+=h*3600+m*60+s;  
            else  
            {  
                gets(str);  
                flag=0;  
            }  
        }  
        if(flag)  
        {  
            sum=sum/d+0.5;  
            printf("%3d: %d:%02d min/km\n",t,sum/60,sum%60);  
        }  
        else  
            printf("%3d: -\n",t);  
    }  
    return 0;  
}  