#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
int main()
{
    int x;
    int ans;
    while(scanf("%d",&n)!=EOF)
    {
        ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            ans^=x;
        }
        if(ans)
        {
            cout<<"Win"<<endl;
        }
        else
        {
            cout<<"Lose"<<endl;
        }
    }
    return 0;
}