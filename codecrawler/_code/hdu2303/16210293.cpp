#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <malloc.h>
#include <ctype.h>
#include <math.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 11111
#include <queue>
#include <vector>
#define LL long long
const int INF = 999999;
int pri[1000003],prim[333334];
char s[222];
int main()
{
    //freopen("in.txt","r",stdin);
    int k,num=0;
    memset(pri,0,sizeof(pri));
    for(int i=2; i<=1000000; i++){
        if(pri[i]==0){
            prim[num++]=i;
            for(int j=i*2; j<=1000000; j+=i)
                pri[j]=1;
        }
    }
    while(scanf("%s %d",s,&k))
    {
        if(k==0&&s[0]=='0') break;
        int len=strlen(s);
        int sum=0,minn=10000003,i;
        for( i=0;i<num; i++)
        {
            sum=0;
            for( int j=0;j<len;j++)
                sum=(sum*10+(s[j]-'0'))%prim[i];//mod
            if(sum==0)//getans
                break;
        }
        if(i!=num&&prim[i]<k)//out
            printf("BAD %d\n",prim[i]);
        else printf("GOOD\n");
    }
    return 0;
}