#include<stdio.h>
#include<math.h>
#include <queue>
#include<algorithm>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        priority_queue < int >q;
        int n;
        cin>>n;
        while(n--)
        {
            int num;
            scanf("%d",&num);
            if(q.empty())q.push(num);
            else
            {
                if(q.size()<2)q.push(num);
                else
                {
                    if(num<q.top())
                    {
                        q.push(num);
                        q.pop();
                    }
                }
            }
        }
        printf("%d\n",q.top());
    }

    return 0;
}