#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int head;
    int end;
    int flag;
} node[5005];

int cmp(struct Node a,struct Node b)
{
    if(a.head < b.head)
    return 1;
    else if(a.head == b.head)
    return a.end < b.end;
    return 0;
}

int main()
{
    int n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int i,j,sum = 0,cnt = 0;
        for(i = 0; i<n; i++)
        {
            cin >> node[i].head >> node[i].end;
            node[i].flag = 0;
        }
        sort(node,node+n,cmp);
        int ans = 0;
        for(i = 0; i<n; i++)
        {
            if(!node[i].flag)
            {
                node[i].flag = 1;
                ans++;
                int end = node[i].end;
                for(int j = i+1; j < n; j++)
                {
                    if(!node[j].flag && node[j].end >= end)
                    {
                        node[j].flag = 1;
                        end = node[j].end;
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
