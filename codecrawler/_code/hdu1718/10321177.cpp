#include<stdio.h>
#include<string.h>
char a[1001][9];
int b[1001],c[102];
int main()
{
    while(gets(a[0]))
    {
        int i=1,flag=0,j;
        memset(c,0,sizeof(c));
        while(scanf("%s%d",a[i],&b[i])!=EOF)
        {
            if(a[i][0]=='0') break;
            if(strcmp(a[0],a[i])==0) flag=i;
            c[b[i]]++;
            i++;
        }
        int rank=0;
        for(j=100; j>=0; j--)
        {
            if(j==b[flag])
            {
                printf("%d\n",rank+1);
                break;
            }
            if(c[j]) rank+=c[j];
        }
        getchar();
    }
    return 0;
}