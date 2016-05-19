#include <stdio.h>
#define SIZE 168

int main()
{
    int flag = 0;
    int x, v;
    while(scanf("%d",&x)!=EOF)
    {
        if(x<=SIZE) 
        {
            flag++;
            if(flag == 1) v = x;
        }
    }
    if(flag) 
        printf("CRASH %d\n",v);
    else  
        printf("NO CRASH\n");
    return 0;
}