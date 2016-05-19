#include<stdio.h>
#include<string.h>

bool map[502][502];

int main ()
{
    int t ,n ,m ,w ,i ,j ,sum ,cas = 1 ,x ,y;
    scanf("%d" ,&t);
    while(t--)
    {
        scanf("%d %d" ,&n ,&m);
        for(i = 0 ;i <= n+1 ;i ++)
        for(j = 0 ;j <= m+1 ;j ++)
        map[i][j] = 0;
        scanf("%d" ,&w);
        sum = 0;
        while(w--)
        {
            scanf("%d %d" ,&x ,&y);
            if(!map[x][y] ++) sum ++;
        }
        while(1)
        {
            int s = 0;
            for(i = 1 ;i <= n ;i ++)
            for(j = 1 ;j <= m ;j ++)
            {
                if(map[i][j]) continue;
                int mk = 0;
                if(map[i-1][j] && (map[i][j+1] || map[i][j-1])) mk = 1;
                if(map[i+1][j] && (map[i][j+1] || map[i][j-1])) mk = 1;
                s += mk;
                if(mk) map[i][j] = 1;
            }
            sum += s;
            if(!s) break;
        }
        printf("Case #%d:\n" ,cas ++);
        printf("%d\n" ,sum);
    }
    return 0;
}

