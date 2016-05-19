#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *a,const void *b)
{
    return strcmp((char *)a,(char *)b);
}
int main()
{
    int n,i,k,max_plat;
    char  str[1000][16];
    char  temp[16];
    while(scanf("%d",&n)!=EOF&&n)
    {
        getchar();
        i=0;
        max_plat=1;
        while(n--)
        {
            gets(str[i++]);
        }
        
        strcpy(temp,str[0]);
        qsort(str,i,sizeof(char)*16,cmp);
        for(k=1;k<i;k++)
        {
            if(strcmp(str[k],str[k-max_plat])==0)
            {
                max_plat++;
                strcpy(temp,str[k]);
            }
        }
        puts(temp);
    }
}