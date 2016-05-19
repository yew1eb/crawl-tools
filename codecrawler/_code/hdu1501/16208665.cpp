#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char str1[205],str2[205],str3[405];
int flag;
int len1,len2,len3;
int hash[205][205];
void dfs(int a,int b,int c)
{
    if(flag)
    return;
    if(c==len3)
    {
        flag=1;
        return;
    }
    if(hash[a][b])
    return;
    hash[a][b]=1;
    if(str1[a]==str3[c])
    dfs(a+1,b,c+1);
    if(str2[b]==str3[c])
    dfs(a,b+1,c+1);
}
int main()
{
    int i,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%s%s%s",str1,str2,str3);
        printf("Data set %d: ",i);
        len1=strlen(str1);
        len2=strlen(str2);
        len3=strlen(str3);
        if(len1+len2!=len3)
        {
            printf("no\n");
            continue;
        }
        memset(hash,0,sizeof(hash));
        flag=0;
        dfs(0,0,0);
        if(flag)
        printf("yes\n");
        else
        printf("no\n");
    }
    return 0;
}
    
