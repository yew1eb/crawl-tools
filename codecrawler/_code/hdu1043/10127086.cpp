#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<string>
using namespace std;
const int MAXN=1000000;//×î¶àÊÇ9!/2
int fac[]={1,1,2,6,24,120,720,5040,40320,362880};//¿µÍÏÕ¹¿ªÅÐÖØ
//         0!1!2!3! 4! 5!  6!  7!   8!    9!
bool vis[MAXN];//±ê¼Ç
string path[MAXN];//¼ÇÂ¼Â·¾¶
int cantor(int s[])//¿µÍÏÕ¹¿ªÇó¸ÃÐòÁÐµÄhashÖµ
{
    int sum=0;
    for(int i=0;i<9;i++)
    {
        int num=0;
        for(int j=i+1;j<9;j++)
          if(s[j]<s[i])num++;
        sum+=(num*fac[9-i-1]);
    }
    return sum+1;
}
struct Node
{
    int s[9];
    int loc;//¡°0¡±µÄÎ»ÖÃ
    int status;//¿µÍÏÕ¹¿ªµÄhashÖµ
    string path;//Â·¾¶
};
int move[4][2]={{-1,0},{1,0},{0,-1},{0,1}};//u,d,l,r
char indexs[5]="durl";//ºÍÉÏÃæµÄÒªÏà·´£¬ÒòÎªÊÇ·´ÏòËÑË÷
int aim=46234;//123456780¶ÔÓ¦µÄ¿µÍÏÕ¹¿ªµÄhashÖµ
void bfs()
{
    memset(vis,false,sizeof(vis));
    Node cur,next;
    for(int i=0;i<8;i++)cur.s[i]=i+1;
    cur.s[8]=0;
    cur.loc=8;
    cur.status=aim;
    cur.path="";
    queue<Node>q;
    q.push(cur);
    path[aim]="";
    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        int x=cur.loc/3;
        int y=cur.loc%3;
        for(int i=0;i<4;i++)
        {
            int tx=x+move[i][0];
            int ty=y+move[i][1];
            if(tx<0||tx>2||ty<0||ty>2)continue;
            next=cur;
            next.loc=tx*3+ty;
            next.s[cur.loc]=next.s[next.loc];
            next.s[next.loc]=0;
            next.status=cantor(next.s);
            if(!vis[next.status])
            {
                vis[next.status]=true;
                next.path=indexs[i]+next.path;
                q.push(next);
                path[next.status]=next.path;
            }
        }
    }

}
int main()
{
    char ch;
    Node cur;
    bfs();
    while(cin>>ch)
    {
        if(ch=='x') {cur.s[0]=0;cur.loc=0;}
        else cur.s[0]=ch-'0';
        for(int i=1;i<9;i++)
        {
            cin>>ch;
            if(ch=='x')
            {
                cur.s[i]=0;
                cur.loc=i;
            }
            else cur.s[i]=ch-'0';
        }
        cur.status=cantor(cur.s);
        if(vis[cur.status])
        {
            cout<<path[cur.status]<<endl;
        }
        else cout<<"unsolvable"<<endl;
    }
    return 0;
}
