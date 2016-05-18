//并不需要把四个方向的都判断了
//只要选择其中的两个俄方向就可以
#include<iostream>
#include<cstdio>
#define maxn 51
using namespace std;
//分别表示上下左右四边是否有接口，'0'无，'1'有
char a[11][5]={"1010","1001","0110","0101","1100","0011",
               "1011","1110","0111","1101","1111"};
int f[maxn][maxn];
char g[maxn][maxn];
int n,m;
int find(int x)
{
    if(f[x/n][x%n]==x)
    return x;
    return f[x/n][x%n]=find(f[x/n][x%n]);
}
void Union(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x!=y)
    f[y/n][y%n]=x;
}
void judge(int i,int j)//判断g[i][j]和它的左侧上侧是否连通 若连通则合并
{
    if(j>0&&a[g[i][j]-'A'][2]=='1'&&a[g[i][j-1]-'A'][3]=='1')
    Union(i*n+j,i*n+j-1);
    if(i>0&&a[g[i][j]-'A'][0]=='1'&&a[g[i-1][j]-'A'][1]=='1')
    Union(i*n+j,i*n+j-n);
}
int main()
{
    int i,j,count;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        if(n==-1&&m==-1)
        break;
        for(i=0;i<m;i++)
        {
            scanf("%s",g[i]);
            for(j=0;j<n;j++)
            f[i][j]=i*n+j;
        }
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
            judge(i,j);
        int cnt=0;
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                if(f[i][j]==i*n+j)
                    cnt++;
        cout<<cnt<<endl;
    }
}