#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int flag;
int num[4];
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
void dfs(int sum,int cur,int m)
{
    if(flag)
    return;
    if(m==3)
    {
        if(sum+cur==24||sum-cur==24||sum*cur==24)
        flag=1;
        if(cur!=0&&sum%cur==0&&sum/cur==24)
        flag=1;
        return;
    }
    dfs(sum+cur,num[m+1],m+1);  //åè®¡ç®åä¸é¨å
    dfs(sum-cur,num[m+1],m+1);
    dfs(sum*cur,num[m+1],m+1);
    if(cur!=0&&sum%cur==0)
    dfs(sum/cur,num[m+1],m+1);
    dfs(sum,cur+num[m+1],m+1);  //åè®¡ç®åä¸é¨åï¼ç¸å½äºå æ¬å·
    dfs(sum,cur-num[m+1],m+1);
    dfs(sum,cur*num[m+1],m+1);
    if(num[m+1]!=0&&cur%num[m+1]==0)
    dfs(sum,cur/num[m+1],m+1);
}
int main()
{
    int i;
    char str[5];
    while(scanf("%s",str)!=EOF)
    {
        if(strlen(str)==2)
        num[0]=10;
        else
        {
            if(str[0]=='A')
            num[0]=1;
            else if(str[0]=='J')
            num[0]=11;
            else if(str[0]=='Q')
            num[0]=12;
            else if(str[0]=='K')
            num[0]=13;
            else
            num[0]=str[0]-'0';
        }
        for(i=1;i<=3;i++)
        {
            scanf("%s",str);
            if(strlen(str)==2)
            num[i]=10;
            else
            {
               if(str[0]=='A')
               num[i]=1;
               else if(str[0]=='J')
               num[i]=11;
               else if(str[0]=='Q')
               num[i]=12;
               else if(str[0]=='K')
               num[i]=13;
               else
               num[i]=str[0]-'0';
            }
        }
        qsort(num,4,sizeof(num[0]),cmp);
        flag=0;
        do
        {
            dfs(num[0],num[1],1);
        }while(next_permutation(num,num+4)&&!flag);
        if(flag)
        printf("Yes\n");
        else
        printf("No\n");
    }
    return 0;
}
