#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <cstring>
#include <climits>
#include <cmath>
#include <cctype>

using namespace std;

const int maxn = 40000;
int select[maxn],nselect;
bool beselect[maxn];

void doselect()
{
    int i,j;
    nselect = 0;
    memset(beselect,true,sizeof(beselect));
    for(i=2; i<maxn; i++)
    {
        if(beselect[i])
        {
            select[++nselect] = i;
            int sum = 0;
            for(j=i+1; j<maxn; j++)
            {
                if(beselect[j])
                {
                    sum++;
                    if(sum == i)
                    {
                        sum = 0;
                        beselect[j] = false;
                    }
                }
            }
        }
    }
}

int main()
{
    int n;
    doselect();
    while(scanf("%d",&n) && n)
    {
        printf("%d\n",select[n]);
    }
    return 0;
}