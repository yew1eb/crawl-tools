#include<stdio.h>
int n,m;
int find(int a[][50])
{
    int i,j;
    for(i=1;i<n;i++)
        for(j=1;j<m;j++)
        {
            if(a[i][j]==0&&a[i-1][j]==0&&a[i][j-1]==0&&a[i-1][j-1]==0)
            {
                int t[50][50];
                for(int ii=0;ii<n;ii++)
                        for(int jj=0;jj<m;jj++)
                           t[ii][jj]=a[ii][jj];
                t[i][j]=1;t[i-1][j]=1;t[i][j-1]=1;t[i-1][j-1]=1;
                if(find(t)==0) return 1;//æ³¨æè¿éåªè¦æä¸ä¸ªåç»§æ»¡è¶³æ¯å¿è´¥æå®å°±æ¯å¿èæ
            }
        }
        return 0;//ææåç»§é½æ¯å¿èæå®æ¯å¿è´¥æ
}
int main()
{
    int i,j,a[50][50];
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%1d",&a[i][j]);
             //   printf("dd");
        int ans=find(a);
        if(ans!=0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
