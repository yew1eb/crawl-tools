#include<cstdio>
#include<cstring>
#include<queue>
#define N 110                 //N要开的稍微大点，我开成100错了、、、
using namespace std;
struct stu
{
    int x,y;
}p[N*N+10];
int a[N+10][N+10],pri[N*N+10]={1,1,0},s[N+10][N+10];
void sxjz()                 //构造符合题意的矩阵
{
    int i=0,j=0,t=N*N;
    memset(a,0,sizeof(a));
    while(t>0){
        while(j<N&&!a[i][j]){
            p[t].x=i;
            p[t].y=j;
            a[i][j++]=t--;
        }
        j--;
        i++;
        while(i<N&&!a[i][j]){
            p[t].x=i;
            p[t].y=j;
            a[i++][j]=t--;
        }
        i--;
        j--;
        while(j>=0&&!a[i][j]){
            p[t].x=i;
            p[t].y=j;
            a[i][j--]=t--;
        }
        j++;
        i--;
        while(i>=0&&!a[i][j]){
            p[t].x=i;
            p[t].y=j;
            a[i--][j]=t--;
        }
        i++;
        j++;
    }
}
void prime()               //筛选法求素数
{
    int i,j;
    for(i=2;i<=N*N;i++)
        if(pri[i]==0)
            for(j=i+i;j<=N*N;j+=i)
                pri[j]=1;
}
int bfs(int m,int n)
{
    int i,j;
    struct stu t;
    queue<struct stu> q;
    q.push(p[m]);
    s[p[m].x][p[m].y]=1;
    while(!q.empty()){
        t=q.front();
        q.pop();
        i=t.x;
        j=t.y;
        if(a[i][j]==n)
            return s[i][j]-1;
        if(i<N-1&&pri[a[i+1][j]]&&!s[i+1][j]){
            t.x=i+1;
            t.y=j;
            q.push(t);
            s[i+1][j]=s[i][j]+1;
        }
        if(i>0&&pri[a[i-1][j]]&&!s[i-1][j]){
            t.x=i-1;
            t.y=j;
            q.push(t);
            s[i-1][j]=s[i][j]+1;
        }
        if(j<N-1&&pri[a[i][j+1]]&&!s[i][j+1]){
            t.x=i;
            t.y=j+1;
            q.push(t);
            s[i][j+1]=s[i][j]+1;
        }
        if(j>0&&pri[a[i][j-1]]&&!s[i][j-1]){
            t.x=i;
            t.y=j-1;
            q.push(t);
            s[i][j-1]=s[i][j]+1;
        }
    }
    return -1;
}
int main()
{
    int m,n,k=0,t;
    prime();
    sxjz();
    while(scanf("%d%d",&m,&n)!=EOF){
        k++;
        memset(s,0,sizeof(s));
        t=bfs(m,n);
        if(t!=-1)
            printf("Case %d: %d\n",k,t);
        else
            printf("Case %d: impossible\n",k);
    }
    return 0;
}