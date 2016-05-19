#include<cstdio>
#include<cstring>
int map[501][501],n;
void floyed()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
        if(map[i][k])
        {
            for(int j=1;j<=n;j++)
            map[i][j]=map[i][j]||map[i][k]&&map[k][j];
        }
}
int main()
{
    int t,a,b,m,count;
    scanf("%d",&t);
    while(t--)
    {
       count=0;
       memset(map,0,sizeof(map));
       scanf("%d%d",&n,&m);
       while(m--)
       {
           scanf("%d%d",&a,&b);
           map[a][b]=1;
       }
       floyed();
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            if(!(map[i][j]||map[j][i])) count++;
        printf("%d\n",count);
    }
    return 0;
}
