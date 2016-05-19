#include <iostream>
#include<cstring>
#include <cmath>
#include <queue>
using namespace std;
bool mark[10000];
int a[5]={1,10,100,1000,10000};
int prim(int n)
{
    int t=sqrt(n*1.0)+1;
    if(n==2)
    return 1;
    for(int i=2;i<t;i++)
    if(n%i==0)
    return 0;
    return 1;
}
int n,k;
int bfs()
{
     queue<int> q;
     int t,s,num,step=0,temp;
     q.push(n);
     mark[n]=true;
     if(n==k)
     return 0;
     while(!q.empty())
     {
                      s=q.size();
                      step++;
                      while(s--)
                      {
                                t=q.front();
                                q.pop();
                                for(int i=0;i<4;i++)
                                {
                                        temp=t/a[i]-10*(t/a[i+1]);
                                        //cout <<temp<<" ";
                                        for(int j=-temp;j<10-temp;j++)
                                        {
                                                num=t+a[i]*j;
                                                if(num==k)
                                                {
                                                          return step;
                                                }
                                                if(num>9999 || num<1000)
                                                continue;
                                                if(prim(num) && !mark[num])
                                                {
                                                            // cout<<num<<" ";
                                                            mark[num]=true;
                                                            q.push(num);
                                                }
                                        }

                                }

                      }
                      //cout <<endl;
     }
}

int main()
{
    int t;
    cin >>t;
    while(t--)
    {
    memset(mark,false,sizeof(mark));
    cin >>n>>k;
    cout <<bfs()<<endl;
    }
    return 0;
}
