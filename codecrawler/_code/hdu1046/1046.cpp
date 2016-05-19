#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int T;cin>>T;
    int k=1;
    int n,m;
    while (T--)
    {
        cin>>n>>m;
        if(n&1 && m&1)
            printf("Scenario #%d:\n%.2f\n",k++,double(n*m+0.41));
        else printf("Scenario #%d:\n%d.00\n",k++,n*m);
        cout<<endl;
    }
    return 0;
}