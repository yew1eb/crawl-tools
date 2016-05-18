#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct que
{
    int a[4][4];
    int step;
    int b[5];
};
queue<que> q;
bool v[5][5][5][5][5][5][5][5][5];
int step[10][10][10][10];
const int dx[5]={0,1,0,-1,0},dy[5]={0,0,1,0,-1};
que t;
int maxw,w[5],sec,sum=0;
int work()
{
    int s1,s2,s3,x,y,last;
    while(!q.empty())
    {
        t=q.front();q.pop();
        if(t.step<step[t.b[1]][t.b[2]][t.b[3]][t.b[4]])
        step[t.b[1]][t.b[2]][t.b[3]][t.b[4]]=t.step;
        for(int i=1;i<=3;i++)
         for(int j=1;j<=3;j++)
        {
            sum++;
            last=t.a[i][j];
            //debug
            //yell
            s1=0,s2=0,s3=0;
             for(int k=1;k<=4;k++)
            {
                x=i+dx[k];y=j+dy[k];
                if(x>=1&&y>=1&&x<=3&&y<=3&&t.a[x][y]==1)s1++;
                if(x>=1&&y>=1&&x<=3&&y<=3&&t.a[x][y]==2)s2++;
                if(x>=1&&y>=1&&x<=3&&y<=3&&t.a[x][y]==3)s3++;
            }
              if(s1>0&&s2>0&&s3>0&&t.a[i][j]!=4)
            {
                t.a[i][j]=4;t.b[last]--;t.b[4]++;
                t.step++;
                   if(!v[t.a[1][1]][t.a[1][2]][t.a[1][3]][t.a[2][1]][t.a[2][2]][t.a[2][3]][t.a[3][1]][t.a[3][2]][t.a[3][3]])
                {
                    v[t.a[1][1]][t.a[1][2]][t.a[1][3]][t.a[2][1]][t.a[2][2]][t.a[2][3]][t.a[3][1]][t.a[3][2]][t.a[3][3]]=true;
                   //debug
                    q.push(t);
                }
                t.a[i][j]=last;
                t.b[last]++;t.b[4]--;
                t.step--;
            }
            //green
            s1=0,s2=0;
             for(int k=1;k<=4;k++)
            {
                x=i+dx[k];y=j+dy[k];
                if(x>=1&&y>=1&&x<=3&&y<=3&&t.a[x][y]==1)s1++;
                if(x>=1&&y>=1&&x<=3&&y<=3&&t.a[x][y]==2)s2++;
            }
              if(s1>0&&s2>0&&t.a[i][j]!=3)
            {
                t.a[i][j]=3;t.b[last]--;t.b[3]++;
                t.step++;
                    if(!v[t.a[1][1]][t.a[1][2]][t.a[1][3]][t.a[2][1]][t.a[2][2]][t.a[2][3]][t.a[3][1]][t.a[3][2]][t.a[3][3]])
                {
                    v[t.a[1][1]][t.a[1][2]][t.a[1][3]][t.a[2][1]][t.a[2][2]][t.a[2][3]][t.a[3][1]][t.a[3][2]][t.a[3][3]]=true;
                    q.push(t);
                }
                t.a[i][j]=last;
                t.b[last]++;t.b[3]--;
                t.step--;
            }
              //red
            s1=0;
            for(int k=1;k<=4;k++)
            {
                x=i+dx[k];y=j+dy[k];
                if(x>=1&&y>=1&&x<=3&&y<=3&&t.a[x][y]==1)s1++;
            }
             if(s1>0&&t.a[i][j]!=2)
            {
                t.a[i][j]=2;
                t.step++;t.b[last]--;t.b[2]++;
                  if(!v[t.a[1][1]][t.a[1][2]][t.a[1][3]][t.a[2][1]][t.a[2][2]][t.a[2][3]][t.a[3][1]][t.a[3][2]][t.a[3][3]])
                {
                    v[t.a[1][1]][t.a[1][2]][t.a[1][3]][t.a[2][1]][t.a[2][2]][t.a[2][3]][t.a[3][1]][t.a[3][2]][t.a[3][3]]=true;
                    q.push(t);
                }
                t.a[i][j]=last;
                t.b[last]++;t.b[2]--;
                t.step--;
            }
              //blue
            if(t.a[i][j]!=1)
            {
                t.step++;
                t.a[i][j]=1;t.b[last]--;t.b[1]++;
                 if(!v[t.a[1][1]][t.a[1][2]][t.a[1][3]][t.a[2][1]][t.a[2][2]][t.a[2][3]][t.a[3][1]][t.a[3][2]][t.a[3][3]])
                {
                    v[t.a[1][1]][t.a[1][2]][t.a[1][3]][t.a[2][1]][t.a[2][2]][t.a[2][3]][t.a[3][1]][t.a[3][2]][t.a[3][3]]=true;
                    q.push(t);
                }
                t.a[i][j]=last;
                t.b[last]++;t.b[1]--;
                t.step--;
            }
        }
    }
    return -1;
}
int main()
{
    for(int i=0;i<=9;i++)
     for(int j=0;j<=9;j++)
      for(int k=0;k<=9;k++)
       for(int z=0;z<=9;z++)
       step[i][j][k][z]=1<<28;
    w[1]=1;w[2]=2;w[3]=3;w[4]=4;maxw=1<<28;
    for(int i=1;i<=3;i++)
    for(int j=1;j<=3;j++)
    t.a[i][j]=0;
    t.step=0;
    t.b[1]=t.b[2]=t.b[3]=t.b[4]=0;
    memset(v,false,sizeof(v));
    v[0][0][0][0][0][0][0][0][0]=true;
    q.push(t);
    int ans=work();

    sec=0;w[0]=0;
    while(scanf("%d",&w[1]),w[1])
    {
        sec++;
        scanf("%d%d%d%d",&w[2],&w[3],&w[4],&maxw);
        ans=1<<28;
        for(int i=0;i<=9;i++)
         for(int j=0;j<=9;j++)
          for(int k=0;k<=9;k++)
           for(int z=0;z<=9;z++)
           if(i*w[1]+j*w[2]+k*w[3]+z*w[4]>=maxw && step[i][j][k][z]<ans)
           ans=step[i][j][k][z];
        printf("Case %d: ",sec);
        if(ans==1<<28)
        printf("Impossible\n");
        else
        printf("%d\n",ans);
    }
    return 0;
}