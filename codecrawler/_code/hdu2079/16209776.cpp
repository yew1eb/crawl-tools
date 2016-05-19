#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>

int g[9],la[55],lb[55];
using namespace std;
int main(int argc, char *argv[])
{
    int t,n,k,a,b;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        memset(g,0,sizeof(g));
        for(int i = 0; i < k; i++)
        {
            cin>>a>>b;
            g[a] = b;
        }
        memset(la,0,sizeof(la));
        memset(lb,0,sizeof(lb));
        for(int i = 0; i <= g[1]; i++)
            la[i] = 1;
        for(int i = 2; i <= 8; i++)
        {
            for(int j = 0; j <= 40; j++)
            {
                for(int k = 0,s = 0; (s<=g[i])&&(j+k<=40); k+=i,s++)
                    lb[j+k] += la[j];
            }
            for(int j = 0; j <= 40; j++)
            {
                la[j] = lb[j];
                
                lb[j] = 0;
            }
        
        }
        cout<<la[n]<<endl;
    }
    return 0;
}