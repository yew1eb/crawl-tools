#include <iostream>
#include <cstring>
#include <cstdio>
#define INF 0x3f3f3f3f
#define BUG printf("here!\n")
using namespace std;
int map[10][10];
struct node
{
    int x,y;
};
node num[90];
int k;
int ff;
int judge(int digit,int x,int y)
{
    int i,j;
    for(i=0;i<9;i++)
    {
        if(map[x][i]==digit||map[i][y]==digit)
            return 0;
    }
    int n=x/3;
    int m=y/3;
    for(i=n*3;i<n*3+3;i++)
    {
        for(j=m*3;j<m*3+3;j++)
        {
            if(map[i][j]==digit)
                return 0;
        }
    }
    return 1;
}
int dfs(int x)
{
    int i,j;
    if(x==k)
    {
        if(ff==0)
            printf("\n");
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
                if(j==0)
                    printf("%d",map[i][j]);
                else
                    printf(" %d",map[i][j]);
            printf("\n");
        }
        ff=0;
    }
    for(i=1;i<=9;i++)
    {
        if(judge(i,num[x].x,num[x].y))
        {
            map[num[x].x][num[x].y]=i;
            if(dfs(x+1))
                return 1;
            map[num[x].x][num[x].y]=0;
        }
    }
    return 0;
}
int main()
{
    char s[5];
    int i=0,j=0;
    k=0;
    ff=1;
    while(scanf("%s",s)!=EOF)
    {
        if(s[0]=='?')
        {
            map[i][j]=0;
            num[k].x=i;
            num[k].y=j;
            k++;
        }
        else
            map[i][j]=s[0]-'0';
        j++;
        if(j==9)
        {
            i=i+1;
            j=0;
        }
        if(i==9&&j==0)
        {
            dfs(0);
            i=0,j=0;
            k=0;
        }


    }
    return 0;
}
