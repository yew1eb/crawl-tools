#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <malloc.h>
#include <ctype.h>
#include <math.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#include <stack>
#include <queue>
#include <vector>
#include <deque>
#include <set>
#include <map> 


typedef __int64 ll; 

 
ll op[100100];
ll num[100100];

ll bit[70];

void deal(ll wei,ll x)
{
    ll ji=1;//åä¸ä¸ª
    while(wei)
    {
        bit[ji]+=x*(wei+1)/2; 
        wei-=(wei+1)/2;
        ji++;
    }
}

struct point 
{
    ll num,bit;
};
point tnum[70];

ll cmp(point a,point b)
{
    return a.num<b.num;
}

int main()
{
    ll n;
    scanf("%I64d",&n);
    ll len=1;
    for(ll i=1;i<=n;i++)
    {
        scanf("%I64d",&op[i]);

        if(op[i]&1)
        {
            scanf("%I64d",&num[len++]);
        }
        else
        {
            ll l,r,kk;

            scanf("%I64d%I64d%I64d",&l,&r,&kk);


            memset(bit,0,sizeof bit);
            deal(r,1);
            deal(l-1,-1);

            for(ll i=1;i<=65;i++)//åä¸ä¸ª æ¯ sum[len-i];
            {
                tnum[i].bit=bit[i];
                tnum[i].num=num[len-i];
            }

            sort(tnum+1,tnum+1+65,cmp);

            for(ll i=1;i<=65;i++)
            {
                kk-=tnum[i].bit;
                if(kk<=0)
                {
                    printf("%I64d\n",tnum[i].num);
                    break;
                }
            }
        }

    }
    return 0;
}
 