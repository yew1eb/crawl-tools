#include<stdio.h>
#include<string.h>
#define N 100010
#define M 100010
char a[N],b[M];
int next[M];
int n,m;
int main()
{
    int T,flag,i,j,k,count,can;
    scanf("%d",&T);
    while(T--)
    {
        can=1;
        flag=1;
        count=0;
        scanf("%s",a);
        scanf("%s",b);
        n=strlen(a);
        m=strlen(b);
        if(n==m)
        {
            for(i=0;i<m;i++)
            {
                if(a[i]!=b[i])
                {
                    flag=2;
                    break;
                }
                else
                    continue;
            }
        }
        else
        {
            for(j=1;j<m;j++)
            {
                if(b[j]==b[j-1])
                    continue;
                else
                    break;
            }
            for(i=0;i<j;i++)
            {
                if(a[i]!=b[i])
                {
                    flag=2;
                    can=0;
                    break;
                }
            }
            if(can==1)
            {
                for(i=j;i<n;i++)
                {
                    for(k=j-1;k<m;k++)
                    {
                        if(a[i]==b[k])
                        {
                            count++;
                            break;
                        }
                    }
                    if(count==0)
                        break;
                }
                if(count==n-j)
                    flag=1;
                else
                    flag=0;
            }
        }
        if(flag==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}