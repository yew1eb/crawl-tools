#include<stdio.h>
#include<string.h>
int f[1001][1001];//**1001*1001太大不能定义在主函数，否则直接停止编译**//
int main()
{
    char a[1001],b[1001];
    int i,j,len1,len2;
    while(~scanf("%s %s",a,b))
    {
        len1=strlen(a);
        len2=strlen(b);
        for(i=0;i<=len1;i++)
        {
            f[i][0]=0;
        }
        for(i=0;i<=len2;i++)
        {
            f[0][i]=0;
        }
        for(i=1;i<=len1;i++)
        {
            for(j=1;j<=len2;j++)
            {
                if(a[i-1]==b[j-1])
                {
                    f[i][j]=f[i-1][j-1]+1;
                }
                else
                {
                    f[i][j]=f[i-1][j]>f[i][j-1]?f[i-1][j]:f[i][j-1];
                }
            }
        }
        printf("%d\n",f[len1][len2]);
    }
    return 0;
}