#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stack>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
const int maxn =10000001;
map<string,int> v;
const int MAXN=155;
int maps[MAXN][MAXN];
int d[MAXN];
int sign[MAXN];
int main()
{
    int T;
    while(scanf("%d",&T)!=EOF&&T!=-1)
    {
        char firsts[40];
        char last[40];
        memset(sign,0,sizeof(sign));
        scanf("%s%s",firsts,last);
        char a[40];
        char b[40];
        int len=1;
        v[firsts]=len++;
        v[last]=len++;
        for(int i=1;i<MAXN;i++)
        for(int j=1;j<MAXN;j++)
        if(i==j)
        maps[i][j]=0;
        else
        maps[i][j]=maps[j][i]=maxn;
        for(int i=1;i<MAXN;i++)
        d[i]=(i==1?0:maxn);
        for(int i=1;i<=T;i++)
        {
            int w;
            scanf("%s%s%d",a,b,&w);
            if(v[a]==0)
            v[a]=len++;
            if(v[b]==0)
            v[b]=len++;
            maps[v[a]][v[b]]=min(maps[v[a]][v[b]],w);
            maps[v[b]][v[a]]=min(maps[v[b]][v[a]],w);
        }
        if(strcmp(firsts,last)==0)
        {
            printf("0\n");
            v.clear();   //æ­¤å¤å¿è®°æ¸ç©ºäº,WAæçäº
            continue;
        }
        int k;
        for(int i=1;i<len;i++)
        {
            int mins=maxn;
            for(int j=1;j<len;j++)
            {
                if(d[j]<=mins&&!sign[j])
                {
                    k=j;
                    mins=d[j];
                }
            }
            sign[k]=1;
            for(int j=1;j<len;j++)
            {
                if(d[j]>d[k]+maps[k][j])
                d[j]=d[k]+maps[k][j];
            }
        }
        if(d[2]!=maxn)
        printf("%d\n",d[2]);
        else
        printf("-1\n");
        v.clear();
    }
    return 0;
}
