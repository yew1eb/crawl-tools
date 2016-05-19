#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int a,b;
    scanf("%d %d",&a,&b);

    int Palind[110000],pnum=0;
    int n,m,k,p,q;

    //求所有的回文数

    for(n=1; n<=9; n++)
        Palind[pnum++]=n;
    for(n=1; n<=9; n++)
        Palind[pnum++]=11*n;
    for(n=1; n<=9; n++)
        for(m=0; m<=9; m++)
            Palind[pnum++]=101*n+10*m;
    for(n=1; n<=9; n++)
        for(m=0; m<=9; m++)
            Palind[pnum++]=1001*n+110*m;
    for(n=1; n<=9; n++)
        for(m=0; m<=9; m++)
            for(k=0; k<=9; k++)
                Palind[pnum++]=10001*n+1010*m+100*k;
    for(n=1; n<=9; n++)
        for(m=0; m<=9; m++)
            for(k=0; k<=9; k++)
                Palind[pnum++]=100001*n+10010*m+1100*k;
    for(n=1; n<=9; n++)
        for(m=0; m<=9; m++)
            for(k=0; k<=9; k++)
                for(p=0; p<=9; p++)
                    Palind[pnum++]=1000001*n+100010*m+10100*k+1000*p;
    for(n=1; n<=9; n++)
        for(m=0; m<=9; m++)
            for(k=0; k<=9; k++)
                for(p=0; p<=9; p++)
                    Palind[pnum++]=10000001*n+1000010*m+100100*k+11000*p;
    for(n=1; n<=9; n++)
        for(m=0; m<=9; m++)
            for(k=0; k<=9; k++)
                for(p=0; p<=9; p++)
                    for(q=0; q<=9; q++)
                        Palind[pnum++]=100000001*n+10000010*m+1000100*k+101000*p+10000*q;
    //判断素数
    for(int i=0;i<pnum;i++)
    {
        if(Palind[i]>b)
        {
            break;
        }
        int q = sqrt(Palind[i]) + 1;
        int flag = 0;
        for(int j = 2;j<q;j++)
        {
            if(Palind[i]%j == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0 && Palind[i]>=a)
        {
            printf("%d\n",Palind[i]);
        }
    }

    return 0;
}