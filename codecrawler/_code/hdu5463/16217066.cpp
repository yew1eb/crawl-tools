#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int a[505];

void add()
{
    int sum=0,t=0;
    for(int i=1;i<=500;i++)
    {
        if(a[i])
        {
            sum+=a[i]/64;
            if(a[i]%64) sum++;
            while(sum>=36)
                t++,sum-=36;
        }
    }
    if(sum) t++;
    cout<<t<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
        {
            int s,t;
            cin>>s>>t;
            a[s]+=t;
        }
        add();
    }
}
