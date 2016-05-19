#include <stdio.h>
#include <string.h>

char map[20][20];
int mat[20][20];

int main()
{
    int n,m,t,i,j,step;
    while(~scanf("%d%d%d",&n,&m,&t))
    {
        int flag = 0;
        memset(mat,0,sizeof(mat));
        memset(map,'\0',sizeof(map));
        if(!n && !m)
            break;
        for(i = 0; i<n; i++)
        {
            scanf("%s",map[i]);
        }
        step = 1;
        int x,y,loop = 0;
        x = 0;
        y = t-1;
        while(1)
        {
            if(map[x][y] == 'N' && !mat[x][y])
            {
                mat[x][y] = step;
                x--;
            }
            else if(map[x][y] == 'S' && !mat[x][y])
            {
                mat[x][y] = step;
                x++;
            }
            else if(map[x][y] == 'E' && !mat[x][y])
            {
                mat[x][y] = step;
                y++;
            }
            else if(map[x][y] == 'W' && !mat[x][y])
            {
                mat[x][y] = step;
                y--;
            }
            else if(mat[x][y])//è¾¾å°æ­¤å¤æ¯è¾¾å°äºéå¤ç¹ï¼æä»¥æ­¥æ°è¦-1
            {
                step--;
                loop = step-mat[x][y]+1;
                flag = 1;
                break;
            }
            else if(x < 0 || y<0 || x >= n || y>=m)//è¾¾å°æ­¤å¤æ¶å·²åºçï¼æä»¥æ­¥æ°è¦-1
            {
                step--;
                break;
            }
            step++;
        }
        if(flag)
            printf("%d step(s) before a loop of %d step(s)\n",step-loop,loop);
        else
            printf("%d step(s) to exit\n",step);
    }

    return 0;
}
