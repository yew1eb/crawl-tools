#include <stdio.h>
#include <string.h>

int n,m,cnt;
char map[30][30];
int to[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

void dfs(int i,int j)
{
    cnt++;
    map[i][j] = '#';
    for(int k = 0; k<4; k++)
    {
        int x = i+to[k][0];
        int y = j+to[k][1];
        if(x<n && y<m && x>=0 && y>=0 && map[x][y] == '.')
            dfs(x,y);
    }
    return;
}

int main()
{
    int i,j,fi,fj;
    while(~scanf("%d%d%*c",&m,&n))
    {
        if(m == 0 && n == 0)
            break;
        for(i = 0; i<n; i++)
        {
            for(j = 0; j<m; j++)
            {
                scanf("%c",&map[i][j]);
                if(map[i][j] == '@')
                {
                    fi = i;
                    fj = j;
                }
            }
            getchar();
        }
        cnt = 0;
        //map[i][j] = '#';
        dfs(fi,fj);
        printf("%d\n",cnt);
    }

    return 0;
}
