#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
int s1,s2,s3,s4;
int e1,e2,e3,e4;
int steps;
bool vis[10000];
struct Q
{
    int x[4];
    int steps;
};
void bfs()
{
    queue<Q>q;
    Q temp,now;
    int i,j;
    int x[4];
    int bit[4]={1000,100,10,1};

    while(!q.empty())q.pop();
    temp.x[0]=s1; temp.x[1]=s2;
    temp.x[2]=s3; temp.x[3]=s4;
    temp.steps=0;
    q.push(temp);
    steps=0xfffffff;
    memset(vis,0,sizeof(vis));
    vis[s1*1000+s2*100+s3*10+s4]=1;
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        if(now.x[0]==e1&&now.x[1]==e2&&now.x[2]==e3&&now.x[3]==e4)
        {

            if(steps>now.steps)
            {
                steps=now.steps;
            }
        }
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                x[0]=now.x[0];x[1]=now.x[1];
                x[2]=now.x[2];x[3]=now.x[3];
                temp=now;
                if(j==0)
                {
                    x[i]++;
                    if(x[i]>9)x[i]=1;
                }
                else
                if(j==1)
                {
                    x[i]--;
                    if(x[i]<1)x[i]=9;
                }
                else
                if(j==2)
                {
                    if(i<=0)continue;
                    int t=x[i];
                    x[i]=x[i-1];
                    x[i-1]=t;
                }
                else
                {
                    if(i>=3)continue;
                    int t=x[i];
                    x[i]=x[i+1];
                    x[i+1]=t;
                }
                //printf("%d %d %d %d\n",x[0],x[1],x[2],x[3]);
                if(vis[x[0]*bit[0]+x[1]*bit[1]+x[2]*bit[2]+x[3]*bit[3]])continue;
                vis[x[0]*bit[0]+x[1]*bit[1]+x[2]*bit[2]+x[3]*bit[3]]=1;
                temp.x[0]=x[0];temp.x[1]=x[1];temp.x[2]=x[2];temp.x[3]=x[3];

                temp.steps++;
                q.push(temp);
            }
        }
    }
    return;
}

int main()
{
    int t;
    char str[5];

    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        s1=str[0]-'0'; s2=str[1]-'0';
        s3=str[2]-'0'; s4=str[3]-'0';
        scanf("%s",str);
        e1=str[0]-'0'; e2=str[1]-'0';
        e3=str[2]-'0'; e4=str[3]-'0';
        bfs();
        printf("%d\n",steps);
    }
    return 0;
}