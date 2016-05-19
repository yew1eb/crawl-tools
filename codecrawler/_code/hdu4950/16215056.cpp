#include<stdio.h>
#define ll __int64
int main()
{
    ll cas=1;
    ll h,a,b,k;
    while(scanf("%I64d %I64d %I64d %I64d",&h,&a,&b,&k)!=EOF)
    {
        if(h==0 && a==0 && b==0 && k==0)
            break;
        printf("Case #%I64d: ",cas++);
        if(h<=a)
        {
            printf("YES\n");
            continue;
        }
        if(a<=b)
            printf("NO\n");
        else
        {
            if(h+(k-1)*(b-a)-a<=0)//kåååæè´¥ä»
                printf("YES\n");
            else 
            {
                if(k*(b-a)+b<0)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
        }
    }
return 0;
}


/*
5 4 3 3
5 6 1 1
4 3 2 2
6 3 2 2
5 3 2 2
0 0 0 0
*/