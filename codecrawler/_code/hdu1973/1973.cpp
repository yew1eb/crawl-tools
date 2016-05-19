/* 
 * File:   hdu1973.cpp
 * Author: ssslpk
 * Created on August 28, 2012, 4:34 PM
 * 题意：给出两个四位数，现要改变第一个数中的个，十，百，千位当中的一个数
 * 使它最终变成第二个数，要求这过程中形成的数是素数，问最少的步骤
 * 
 * 题解：素数筛选＋bfs
 */
#include <cstdlib>
#include<iostream>
#include<string.h>
#include<cstdio>
#include<math.h>
#include<queue>
#define maxn 10002


using namespace std;
int ispri[maxn];
int pri[maxn];
int plen;

void prime()
{
    memset(ispri,1,sizeof(ispri));
    plen=0;
    ispri[1]=ispri[0]=0;
    for(int i=2;i<maxn;i++)
    {
        if(ispri[i])
        {
            pri[plen++]=i;
            for(int j=2*i;j<maxn;j+=i)
                ispri[j]=0;
        }
    }
}
struct node
{
    int num;
    int id;
    int cnt;
};
int serch(int num,int id)
{
    while(id){num/=10;id--;}
    return num%10;
}
queue<node> Q;
int bfs(int s,int e)
{
    if(s==e)return 0;
    node first;
    first.num=s;
    first.id=-1;
    first.cnt=0;
    int vis[maxn];
    memset(vis,0,sizeof(vis));
    Q.push(first);
    vis[s]=1;
    while(!Q.empty())
    {
        node temp=Q.front();
        Q.pop();
        if(temp.num==e)
        {
            while(!Q.empty())Q.pop();
            return temp.cnt;
        }
        for(int j=0;j<4;j++)
        if(temp.id!=j)
        {
            int dig=serch(temp.num,j);
            for(int i=0;i<10;i++)
            if((j != 3 || i != 0)&& dig !=i)
            {
                node p;
                p.num=temp.num -(dig - i)*pow(10,j);
                p.id=j;
                p.cnt=temp.cnt+1;
                if(ispri[p.num]&& !vis[p.num])
                {
                    vis[p.num]=1;
                    Q.push(p);

                }
            }
        }
    }
    
}

int main(int argc, char** argv) {
    prime();
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        int s,e;
        scanf("%d%d",&s,&e);
        printf("%d\n",bfs(s,e));
    }
    return 0;
}