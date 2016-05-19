#include <iostream>
using namespace std;
#define N 105
int n, m;
int map[N][N];
void floyd()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
            {
                if(map[j][i] + map[i][k] < map[j][k])
                    map[j][k] = map[j][i] + map[i][k];
            }
}
int main()
{
    while(~scanf("%d %d", &n, &m))
    {
        //memset(map, 0x1ffffff, sizeof(map));//éè¯¯çåå§åæ¹å¼
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                map[i][j] = 0x1fffffff;
        int x, y;
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d", &x, &y);
            map[x][y] = map[y][x] = 1;
        }
        for(int i = 0; i < n; i++)
            map[i][i]  = 0;
        floyd();
        int flag = 0;
        for(int i = 0; i < n && flag == 0; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(map[i][j] > 7)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 1)
            cout << "No" << endl;
        else 
            cout << "Yes" << endl;
    }
    return 0;
}