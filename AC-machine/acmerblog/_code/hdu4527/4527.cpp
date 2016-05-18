#include<cstdio>
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int a[10][10];
int dir[4][2]={0,1,0,-1,1,0,-1,0};
struct Node
{
    int x,y;
    int flag;
    int d;
    Node(int _x=0,int _y=0,int _flag=0,int _d=0)
    {
        x=_x;
        y=_y;
        flag=_flag;
        d=_d;
    }
};
void print()
{
    for(int i=1;i<=6;i++)
    {
        printf("%d",a[i][1]);
        for(int j=2;j<=6;j++)
                printf(" %d",a[i][j]);
        printf("\n");
    }
    printf("\n");
}
bool judge(int x,int y,int d)
{
    while(x>=1&&x<=6&&y>=1&&y<=6)
    {
        x+=dir[d][0];
        y+=dir[d][1];
        if(a[x][y])
            return 1;
    }
    return 0;
}
void bfs(int x,int y)
{
    queue<Node> q;
    Node t(x,y,1,0);
    q.push(t);
    while(!q.empty())
    {
        Node tmp=q.front();
        q.pop();
        if(tmp.flag)
        {    
            if(a[tmp.x][tmp.y]>4)
            {
                a[tmp.x][tmp.y]=0;
                for(int i=0;i<4;i++)
                {
                    int tx=tmp.x+dir[i][0];
                    int ty=tmp.y+dir[i][1];
                    if(tx<=6&&tx>=1&&ty<=6&&ty>=1)
                        if(a[tx][ty])
                        {
                            a[tx][ty]++;
                            if(a[tx][ty]==5)
                            {
                                Node t(tx,ty,1,0);
                                q.push(t);
                            }    
                        }
                        else
                        { 
                            if(judge(tx,ty,i))
                            {
                                Node t(tx,ty,0,i);
                                q.push(t);
                            }
                                
                        }
                }
            }
        }
        else
        {
            int tx=tmp.x+dir[tmp.d][0];
            int ty=tmp.y+dir[tmp.d][1];
            if(tx<=6&&tx>=1&&ty<=6&&ty>=1)
                if(a[tx][ty])
                {
                    a[tx][ty]++;
                    if(a[tx][ty]==5)
                    {
                        Node t(tx,ty,1,0);
                        q.push(t);
                    }    
                }
                else
                {
                    Node t(tx,ty,0,tmp.d);
                    q.push(t);                                 
                }
        }
    }
}
int main()
{
     while(~scanf("%d", &a[1][1]))
	 {     
        for(int i=1; i<=6; ++i) 
            for(int j=(i==1?2:1); j<=6; ++j) 
                scanf("%d", &a[i][j]);  

        int m;
        cin>>m;
        while(m--)
        {    
            int x,y;
            scanf("%d%d",&x,&y);
            a[x][y]++;
            if(a[x][y]>4)
                bfs(x,y);
        }
        print();
    }
    return 0;
}