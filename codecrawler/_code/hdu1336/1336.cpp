#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int map[30][30];
int indegree[30];
int n,m;

queue<int> q;
queue<int> record;

//拓扑排序
int toposort()
{
    //清空队列
    while(!q.empty())
    {
        q.pop();
    }
    while(!record.empty())
    {
        record.pop();
    }
    int in[30];
    memcpy(in,indegree,sizeof(indegree));
    for(int i=0;i<n;i++)
    {
        if(in[i] == 0)
        {
            q.push(i);
        }
    }

    int flag = 0;
    while(!q.empty())
    {
        int a = q.front();
        record.push(a);
        q.pop();
        if(!q.empty())
        {
            flag = 1;
        }
        for(int i=0;i<n;i++)
        {
            if(map[a][i] == 1)
            {
                in[i]--;
                if(in[i] == 0)
                {
                    q.push(i);
                }
            }
        }
    }
    //有环路
    if(record.size()!=n)
    {
        return 0;
    }
    //不确定排序方式
    else if(flag == 1)
    {
        return 1;
    }
    return 2;//有唯一拓扑
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif

    while(scanf(" %d %d",&n,&m)!=EOF && n!=0 && m!=0)
    {
        memset(map,0,sizeof(map));
        memset(indegree,0,sizeof(indegree));

        int flag = 0;
        for(int i=0;i<m;i++)
        {
            char a,b;
            scanf(" %c<%c",&a,&b);
            if(map[b-'A'][a-'A'] == 1)
            {
                flag = 1;
                printf("Inconsistency found after %d relations.\n",i+1);
                for(int j=i+1;j<m;j++)
                {
                    scanf(" %c<%c",&a,&b);
                }
                break;
            }
            else if(map[a-'A'][b-'A'] == 0)
            {
                map[a-'A'][b-'A'] = 1;
                indegree[b -'A']++;
            }
            int res = toposort();
            if(res == 0)
            {
                flag = 1;
                printf("Inconsistency found after %d relations.\n",i+1);
                for(int j=i+1;j<m;j++)
                {
                    scanf(" %c<%c",&a,&b);
                }
                break;
            }
            else if(res == 2)
            {
                flag = 1;
                for(int j=i+1;j<m;j++)
                {
                    scanf(" %c<%c",&a,&b);
                }
                printf("Sorted sequence determined after %d relations: ",i+1);
                while(!record.empty())
                {
                    int top = record.front();
                    record.pop();
                    printf("%c",top + 'A');
                }
                printf(".\n");
                break;
            }
        }
        if(flag == 0)
        {
            printf("Sorted sequence cannot be determined.\n");
        }

    }
    return 0;
}