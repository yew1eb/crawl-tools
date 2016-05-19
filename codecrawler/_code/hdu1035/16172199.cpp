#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 15;
const int MAXM = 150;

int head[MAXN];

struct EdgeNode
{
    int to;
    int w;
    int next;
};
EdgeNode Edges[MAXM];

char Map[15][15];

int main()
{
    int n,m,d,k;
    while(cin >> n >> m)
    {
        if(n==0 && m==0)
            break;
        cin >> d;
        for(int i = 0; i < n; i++)
            cin >> Map[i];

        memset(head,-1,sizeof(head));
        int i = 0;
        int j = d-1;
        int num = 0;
        while(1)
        {
            char c = Map[i][j];
            if(head[i] == -1)
            {
                Edges[num].to = j;
                Edges[num].w = 1;
                Edges[num].next = head[i];
                head[i] = num;
                num++;
            }
            else
            {
                for(k = head[i]; k != -1; k = Edges[k].next)
                {
                    if(Edges[k].to == j)//
                        break;
                }
                if(k == -1)
                {
                    Edges[num].to = j;
                    Edges[num].w = 1;
                    Edges[num].next = head[i];
                    head[i] = num;
                    num++;
                }
                else
                    break;
            }
            switch(c)
            {
            case 'N':
                i--;
                break;
            case 'W':
                j--;
                break;
            case 'E':
                j++;
                break;
            case 'S':
                i++;
                break;
            }
            if(i < 0 || j < 0 || i >= n || j >= m)
                break;
        }
        if(i < 0 || j < 0 || i >= n || j >= m)
             printf("%d step(s) to exit\n",num);
        else
            printf("%d step(s) before a loop of %d step(s)\n",k,num-k);
    }

    return 0;
}
