#include<iostream>
#include<string.h>
using namespace std;
int map[3][50],no[5] , flag;
void dfs(int n,int a, int b,int c)
{
    if(flag==0) return ;
    if(flag==1) return ;  
    if(n==0) {flag = 1;  return ;}
    if(map[a][no[a]]==n) 
    {
        no[a]++;  dfs(n-1,a,c,b);
    }
    else if(map[c][no[c]]==n)
    {
        no[c]++; dfs(n-1,b,a,c);
    }
    else 
    {
         flag=0;  return ;
    }
}
int main()
{
    int n;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(map,0,sizeof(map));
        scanf("%d",&n);
        for(int i=0;i<3;i++)
        {
             scanf("%d",&no[i]);
             for(int j=0;j<no[i];j++)
             {
                scanf("%d",&map[i][j]);
             }
        }
        no[0]=no[1]=no[2]=0;
        flag = -1;
        dfs(n,0,1,2);
        if(flag) printf("true\n");
        else printf("false\n");
    }
    return 0;
}
