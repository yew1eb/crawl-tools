#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};
char map[10][10];
void init()
{
    int i,j;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
            map[i][j]='X';
    }
}
int s1,s2,e1,e2,t,flag=0;
void DFS(int s1,int s2,int time)
{
    if(flag==1)
        return ;
    if(s1==e1&&s2==e2)
    {
        if(time==t)
        {
            flag=1;
        }
        return ;
    }
    int nowx,nowy,i;
    for(i=0;i<4;i++)
    {
        nowx=s1+xx[i];
        nowy=s2+yy[i];
        if(map[nowx][nowy]!='X')
        {
            time++;

            map[nowx][nowy]='X';
            DFS(nowx,nowy,time);
            map[nowx][nowy]='.';
            time--;
        }
    }
}
int main()
{
    int n,m;
    while(cin>>n>>m>>t,t+n+m)
    {
        init();
        int i,j,time=0,count=0;
        getchar();
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                cin>>map[i][j];
                if(map[i][j]=='D')
                    e1=i,e2=j;
                else if(map[i][j]=='S')
                    s1=i,s2=j;
                else if(map[i][j]=='.')
                    count++;
            }
        }
        if(count+1<t)
        {
            cout<<"NO"<<endl;
            continue;
        }
        flag=0;
        map[s1][s2]='X';

        DFS(s1,s2,time);
        if(flag==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

    }
    return 0;
}
