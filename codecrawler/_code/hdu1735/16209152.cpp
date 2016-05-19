#include"stdio.h"
#include"stdlib.h"
int cmp(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}
int map[10011][100];
int main()
{
    int num[10011],k;
    int n,l,m;
    int i,j;
    int temp;
    int zero;
    while(scanf("%d%d%d",&n,&l,&m)!=-1)
    {
        zero=0;
        for(i=0;i<n;i++)
        for(j=0;j<l;j++)
        {
            scanf("%d",&map[i][j]);
            if(map[i][j]==0)    zero++;
        }


        k=0;
        for(i=1;i<n;i++)
        {
            if(map[i][0]==0&&map[i][1]==0)
            {
                temp=2;
                for(j=l-1;j>=0&&map[i-1][j]==0;j--)    temp++;
                num[k++]=temp;
            }
        }


        qsort(num,k,sizeof(int),cmp);
        for(i=0;i<m-1;i++)    zero-=num[i];
        zero-=2;
        for(j=l-1;j>=0&&map[n-1][j]==0;j--)    zero--;


        printf("%d\n",zero);
    }
    return 0;
}