/*This Code is Submitted by billforum for Problem 2706 at 2012-01-29 19:39:56*/
#include <iostream>
#include <queue>

using namespace std;
int H,W;

struct point{
        int x,y;
        char c;
        int step;
        int key;
        bool f;
};

point data[105][105][16];


int main(int args,char** argv)
{
        char ch;
        int sx,sy,ans,flag,t;
        int dx[4]={0,-1,0,1};
        int dy[4]={-1,0,1,0};
        while(cin>>H>>W&&H&&W)
        {
                ans=0;
                flag=0;
                for(int i=0;i<H;i++)
                        for(int j=0;j<W;j++)
                        {
                                cin>>ch;
                                
                                for(int f=0;f<16;f++)
                                {
                                
                                data[i][j][f].x=j;
                                data[i][j][f].y=i;
                                data[i][j][f].step=0;
                                data[i][j][f].c=ch;
                                data[i][j][f].key=f;
                                data[i][j][f].f=0;
                                if(ch=='*')
                                  {
                                        sx=j;
                                        sy=i;
                                  }
                                }
                        }
                queue<point> list;
                data[sy][sx][0].f=1;
                list.push(data[sy][sx][0]);
                while(!list.empty())
                {
                    point tmp=list.front();
                        if(tmp.c=='X')
                        {
                                flag=1;
                                ans=tmp.step;
                                break;
                        }
                        for(int i=0;i<4;i++)
                        {
                                if(tmp.x+dx[i]>=0&&tmp.x+dx[i]<W&&tmp.y+dy[i]>=0&&tmp.y+dy[i]<H)
                                {
                                        int tx=tmp.x+dx[i];
                                        int ty=tmp.y+dy[i];
                                        int key=tmp.key;
                                        if(data[ty][tx][key].c=='#') continue;
                                        if(data[ty][tx][key].c=='.'||data[ty][tx][key].c=='*'||data[ty][tx][key].c=='X')
                                        {
                                                if(data[ty][tx][key].f==0)
                                                {
                                                        data[ty][tx][key].f=1;
                                                        data[ty][tx][key].step=tmp.step+1;
                                                        list.push(data[ty][tx][key]);
                                                }
                                                continue;
                                        }
//此处写得比较繁琐，这段代码的功能是用于检测字符Y R G B，y r g b；
                                        if(data[ty][tx][key].c=='Y')
                                        {
                                                if((data[ty][tx][key].key&8)!=0)
                                                {
                                                        if(data[ty][tx][key].f==0)
                                                    {
                                                        data[ty][tx][key].f=1;
                                                        data[ty][tx][key].step=tmp.step+1;
                                                        list.push(data[ty][tx][key]);
                                                    }
                                                        continue;
                                                }
                                                continue;
                                        }
                                        if(data[ty][tx][key].c=='R')
                                        {
                                                if((data[ty][tx][key].key&4)!=0) 
                                                {
                                                        if(data[ty][tx][key].f==0)
                                                    {
                                                        data[ty][tx][key].f=1;
                                                        data[ty][tx][key].step=tmp.step+1;
                                                        list.push(data[ty][tx][key]);
                                                    }
                                                        continue;
                                                }
                                                continue;
                                        }
                                        if(data[ty][tx][key].c=='G')
                                        {
                                                if((data[ty][tx][key].key&2)!=0)
                                                {
                                                        if(data[ty][tx][key].f==0)
                                                    {
                                                        data[ty][tx][key].f=1;
                                                        data[ty][tx][key].step=tmp.step+1;
                                                        list.push(data[ty][tx][key]);
                                                    }
                                                        continue;
                                                }
                                                continue;
                                        }
                                        if(data[ty][tx][key].c=='B')
                                        {
                                                if((data[ty][tx][key].key&1)!=0)
                                                {
                                                        if(data[ty][tx][key].f==0)
                                                    {
                                                        data[ty][tx][key].f=1;
                                                        data[ty][tx][key].step=tmp.step+1;
                                                        list.push(data[ty][tx][key]);
                                                    }
                                                        continue;
                                                }
                                                continue;
                                        }
                                    if(data[ty][tx][key].c=='y')
                                    {
                                            int kk=data[ty][tx][key].key|8;
                                                if(data[ty][tx][kk].f==0)
                                                {
                                                        data[ty][tx][kk].f=1;
                                                        data[ty][tx][kk].step=tmp.step+1;
                                                        list.push(data[ty][tx][kk]);
                                                }
                                                continue;
                                     }
                                         if(data[ty][tx][key].c=='r')
                                    {
                                            int kk=data[ty][tx][key].key|4;
                                                if(data[ty][tx][kk].f==0)
                                                {
                                                        data[ty][tx][kk].f=1;
                                                        data[ty][tx][kk].step=tmp.step+1;
                                                        list.push(data[ty][tx][kk]);
                                                }
                                                continue;
                                     }
                                          if(data[ty][tx][key].c=='g')
                                    {
                                            int kk=data[ty][tx][key].key|2;
                                                if(data[ty][tx][kk].f==0)
                                                {
                                                        data[ty][tx][kk].f=1;
                                                        data[ty][tx][kk].step=tmp.step+1;
                                                        list.push(data[ty][tx][kk]);
                                                }
                                                continue;
                                     }
                                          if(data[ty][tx][key].c=='b')
                                    {
                                            int kk=data[ty][tx][key].key|1;
                                                if(data[ty][tx][kk].f==0)
                                                {
                                                        data[ty][tx][kk].f=1;
                                                        data[ty][tx][kk].step=tmp.step+1;
                                                        list.push(data[ty][tx][kk]);
                                                }
                                                continue;
                                     }
                                }
                        }
                list.pop();     

                }
                if(flag==1)
                cout<<"Escape possible in "<<ans<<" steps."<<endl;
        else cout<<"The poor student is trapped!"<<endl;
        }
        
        return 0;
}