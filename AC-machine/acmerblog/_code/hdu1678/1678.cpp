#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        priority_queue<int>q;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            q.push(a);
        }
        int res=0;
        while(!q.empty())
        {
            for(int i=0;i<2;i++)
            {
                if(!q.empty())
                {
                    q.pop();
                }
            }
            if(!q.empty())
            {
                res+=q.top();
                q.pop();
            }
        }
        printf("%d\n",res);
    }
    return 0;
}