#include<iostream>
using namespace std;
char mp[61][61];
int num;
void bfs(int x,int y)
{
    if(x<0||x>51||y<0||y>51)return ;
    if('*'==mp[x][y])return ;
    mp[x][y]='*';
    bfs(x-1,y);bfs(x,y-1);bfs(x,y+1);
    bfs(x+1,y);
}
int readin()
{
    int n,j = 0;
    char tmp;
    for(int i=0;i<51;++i)
        for(int j=0;j<51;++j)
            mp[i][j]=' ';
    if(scanf("%c",&tmp)==EOF)return 0;
    else mp[1][1]=tmp;
    for(int j=2;scanf("%c",&tmp)&&tmp!=10;mp[1][j++]=tmp);
        
        for(n=2;j!=1;++n)
            for(j=1;scanf("%c",&tmp)&&tmp!=10;mp[n][j++]=tmp);
    
    return 1;
}
int main()
{
    int i,j;
    while(readin())
    {
        for(num=0,i=0;i<=51;++i)
            for(j=0;j<=51;++j)
                if(' '==mp[i][j])
                {
                    num++;
                    bfs(i,j);
                }
        printf("%c\n",num==2?'A':'C');
    }
    return 0;
}