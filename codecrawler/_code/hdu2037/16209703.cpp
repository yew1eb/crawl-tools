#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int end,start;
}node[105];

int cmp(struct Node a,struct Node b)
{
    if(a.end!=b.end)
    return a.end < b.end;
}

int main()
{
    int n,i;
    while(cin >> n,n)
    {
        int cnt = 0,time = 0;
        for(i = 0;i<n;i++)
        {
            cin >> node[i].start >> node[i].end;
        }
        sort(node,node+n,cmp);
        for(i = 0;i<n;i++)
        {
            if(node[i].start >= time)
            {
                cnt++;
                time = node[i].end;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}
