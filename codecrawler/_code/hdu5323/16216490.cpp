/*è¸å®ï¼ï¼åªåï¼ï¼*/
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
using namespace std;
int flag;
void dfs(int l,int r)
{
    if(flag&&r>=flag) return ;
    if(l==0){
        if(flag) flag=min(r,flag);
        else flag=r;
        return ;
    }
    if(l<r-l+1) return ;
    int mid=r-l+1;
    dfs(l-mid-1,r);
    dfs(l-mid,r);
    dfs(l,r+mid);
    dfs(l,r+mid-1);
    return ;
}
int main()
{
    int l,r;
    while(scanf("%d%d",&l,&r)!=EOF){
        flag=0;
        if(r==0) {printf("0\n"); continue;}
        dfs(l,r);
        if(flag) printf("%d\n",flag);
        else printf("-1\n");
    }
    return 0;
}
