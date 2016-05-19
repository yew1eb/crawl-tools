#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<cmath>
#define LL long long
using namespace std;
int n,m;
int dir[4][2]={0,1,0,-1,1,0,-1,0};
char str[20][20];
double a[230][230];
bool flag[20][20];
int ans;
const double eps = 1e-12;
double x[230];
bool free_x[230];
int sgn(double x)
{
    return (x>eps)-(x<-eps);
}
int gauss()
{
    int i, j, k;
    int max_r;
    int col;
    double temp;
    int free_x_num;
    int free_index;
    int equ = n*m,var = n*m;
    col = 0;
    memset(free_x,true,sizeof(free_x));
    for (k = 0; k < equ && col < var; k++, col++)
    {
        max_r = k;
        for (i = k + 1; i < equ; i++)
        {
            if (sgn(fabs(a[i][col]) - fabs(a[max_r][col]))>0) max_r = i;
        }
        if (max_r != k)
        {
            for (j = k; j < var + 1; j++) swap(a[k][j], a[max_r][j]);
        }
        if (sgn(a[k][col]) == 0 )
        {
            k--; continue;
        }
        for (i = k + 1; i < equ; i++)
        {
            if (sgn(a[i][col])!=0)
            {
                double t = a[i][col] / a[k][col];
                for (j = col; j < var + 1; j++)
                {
                    a[i][j] = a[i][j] - a[k][j] * t;
                }
            }
        }
    }
    for(i=k;i<equ;i++)
      if(sgn(a[i][col])!=0) {return 0;}
    if (k < var)
    {
        for (i = k - 1; i >= 0; i--)
        {
            free_x_num = 0;
            for (j = 0; j < var; j++)
            {
                if ( sgn(a[i][j])!=0 && free_x[j]){
                    free_x_num++, free_index = j;
                }
            }
            if(free_x_num>1)    continue;
            temp = a[i][var];
            for (j = 0; j < var; j++)
            {
                if (sgn(a[i][j])!=0 && j != free_index) temp -= a[i][j] * x[j];
            }
            x[free_index] = temp / a[i][free_index];
            free_x[free_index] = 0;
        }
        return var - k;
    }

    for (i = var - 1; i >= 0; i--)
    {
        temp = a[i][var];
        for (j = i + 1; j < var; j++)
        {
            if (sgn(a[i][j])!=0) temp -= a[i][j] * x[j];
        }
        x[i] = temp / a[i][i];
    }
    return 1;
}


bool bfs()
{
    int s,e;
    memset(flag,false,sizeof(flag));
    queue<int>x,y;
    while(!x.empty()) x.pop();
    while(!y.empty()) y.pop();
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    if(str[i][j]=='$')
    {
        x.push(i);
        y.push(j);
        s=i;
        e=j;
        flag[i][j]=true;
    }
    while(!x.empty())
    {
        int ux=x.front(),uy=y.front(),vx,vy;
        x.pop();y.pop();
        for(int i=0;i<4;i++)
        {
            vx=ux+dir[i][0];
            vy=uy+dir[i][1];
            if(vx>=0&&vx<n&&vy>=0&&vy<m&&str[vx][vy]!='#'&&!flag[vx][vy])
            {
                flag[vx][vy]=true;
                x.push(vx);y.push(vy);
            }
        }
    }
    return false;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
        scanf("%s",str[i]);
        for(int i=0;i<=n*m;i++)
        for(int j=0;j<=n*m;j++)
            a[i][j]=0;
        bfs();
        int s,e;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            int cnt=0;
            if(str[i][j]=='@')
            {
                s=i;
                e=j;
            }
            if(str[i][j]=='$')//ç®æ çæ¹ç¨ä¾¿æ¯e[i]=0;
            {
                a[i*m+j][n*m]=0;
                a[i*m+j][i*m+j]=1;
                continue;
            }
            if(str[i][j]=='#') //ä¸å¯è¾¾çç¹å¯ä»¥å¿½ç¥
                continue;
            for(int k=0;k<4;k++)
            {
                int x=i+dir[k][0];
                int y=j+dir[k][1];
                if(x>=0&&x<n&&y>=0&&y<m&&str[x][y]!='#'&&flag[x][y])
                {
                    a[i*m+j][x*m+y]=1;
                    cnt++;
                }
             }
                a[i*m+j][n*m]=-1*cnt;
                a[i*m+j][i*m+j]=-1*cnt;
            }
            if(flag[s][e]&&gauss())
            printf("%.6f\n",x[s*m+e]);
            else
            puts("-1");
    }
    return 0;
}
