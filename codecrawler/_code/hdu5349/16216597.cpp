#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<string>
#include<algorithm>
#include<iostream>
#define exp 1e-10
using namespace std;
const int N = 25;
const int inf = 1000000000;
multiset<int> s;
multiset<int>::iterator it;
int main()
{
    int n,i,k,a;
    while(~scanf("%d",&n))
    {
        s.clear();
        for(i=0;i<n;i++)
        {
            scanf("%d",&k);
            if(k==1)
            {
                scanf("%d",&a);
                s.insert(a);
            }
            else if(k==2)
            {
                if(s.empty())
                    continue;
                it=s.begin();
                s.erase(it);
            }
            else if(k==3)
            {
                if(s.empty())
                {
                    printf("0\n");
                    continue;
                }
                it=s.end();
                it--;
                printf("%d\n",*it);
            }
        }
    }
    return 0;
}