#include<stdio.h>
#include<string.h>
int f[100][100];
int max(int x,int y)
{
    if(x<y)
        return y;
    else 
        return x;
}
int main()
{
    int a[100],b[100];
    int n,m,k,s;
    int i,j,l,locate,flag;
    while(scanf("%d%d%d%d",&n,&m,&k,&s)!=EOF)
    {
        memset(f,0,sizeof(f));
        for(i=0;i<k;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
        }
        for(i=0;i<k;i++)
        {
            for(j=b[i];j<=m;j++)//èå
            {
                for(l=1;l<=s;l++)
                {
                    f[j][l]=max(f[j][l],f[j-b[i]][l-1]+a[i]);
                }
            }
        }
        flag = 0;  
        for (i=0;i<=m;i++)  
        {  
            if(flag)  
                break;  
            for (j=0;j<=s;j++)  
            {  
                if (f[i][j]>=n)  
                {  
                    locate = i;  
                    flag = 1;  
                    break;  
                }  
            }  
        }  
        if(flag)  
            printf("%d\n",m-locate);  
        else  
            printf("-1\n");  
    }    
    return 0;
}