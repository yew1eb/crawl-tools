#include<iostream>
#include<map>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int dis[155], len[155][155];
bool visit[155];
#define MAX 0x3f3f3f3f

void Dijsktra(int start, int end)
{
    int k, temp;
    memset(visit, 0, sizeof(visit));
    for(int i = start; i <= end; ++i)
        dis[i] = (i == start ? 0 : MAX); //visit[start] = 1; //å¦ææ è®°ä¸º1ï¼åä¸tempæ¯è¾çå¨é½æ¯MAX
    for(int i = start; i <= end; ++i)
    {
        temp = MAX;
        for(int j = start; j <= end; ++j)
            if(!visit[j] && dis[j] < temp)
                temp = dis[k = j];
        visit[k] = 1;
        if(temp == MAX) break;
        for(int j = start; j <= end; ++j)
            if(dis[j] > dis[k] + len[k][j])
                dis[j] = dis[k] + len[k][j];
    }
}

int main()
{
    int num, iterator, distance, flag;
    char begin[30], end[30];
    char a[30], b[30];
    map<string, int> station;
    while(scanf("%d", &num) != EOF && num != -1)
    {
        station.clear();
        memset(len, MAX, sizeof(len));
        flag = 0;
        scanf("%s%s", begin, end);
        if(strcmp(begin, end) == 0) flag = 1;
        station[begin] = 1;
        station[end] = 2;
        iterator = 3;
        for(int i = 0; i < num; ++i)
        {
            scanf("%s%s%d", a, b, &distance);
            if(!station[a])
                station[a] = iterator++;
            if(!station[b])
                station[b] = iterator++;
                len[station[a]][station[b]] = len[station[b]][station[a]] = distance;
        }
        if(flag)
        {
            printf("0\n");
            continue;
        }
        Dijsktra(1, iterator);
        if(dis[2] == MAX)    printf("-1\n");
        else    printf("%d\n", dis[2]);
    }
    return 0;
}