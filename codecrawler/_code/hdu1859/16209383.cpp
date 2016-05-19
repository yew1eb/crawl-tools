#include <stdio.h>

struct Point{
    int x,y;
}min,max,tmp;

int main(void)
{
    while( scanf("%d %d",&tmp.x, &tmp.y), tmp.x!=0 || tmp.y!=0 )
    {
        min.x = tmp.x;
        min.y = tmp.y;
        max.x = tmp.x;
        max.y = tmp.y;
        while(scanf("%d %d",&tmp.x, &tmp.y), tmp.x!=0 || tmp.y!=0)
        {
            if(tmp.x < min.x)
                min.x = tmp.x;
            if(tmp.x > max.x)
                max.x = tmp.x;
                
            if(tmp.y < min.y)
                min.y = tmp.y;
            if(tmp.y > max.y)
                max.y = tmp.y;
        }
        printf("%d %d %d %d\n", min.x,min.y,max.x,max.y);
    }
    
    return 0;
}
