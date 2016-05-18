#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<string>
using namespace std;
const int maxn=222222;
int next[maxn];
void getnext(char x[])
{
       int i,j;
       int m=strlen(x);
       j=next[0]=-1;
       i=0;
       while(i<m)
       {
              while(j!=-1&&x[i]!=x[j])j=next[j];
              next[++i]=++j;
       }
}
int kmp(char s[],char t[])
{
       int n=strlen(s);
       int m=strlen(t);
       getnext(t);
       int i,j;
       for(i=0,j=0;i<n&&j<m;)
       {
              if(j==-1||s[i]==t[j])
                     ++i,++j;
              else j=next[j];
       }
       if(i>=n)return j;
       return 0;
}
int main()
{
    char s[maxn],t[maxn];
    for(; ~scanf("%s%s",s,t);)
    {
        int x=kmp(s,t);
        int y=kmp(t,s);
        if(x==y)
        {
            if(strcmp(s,t)>0)
            {
                printf("%s",t);
                printf("%s\n",s+x);
            }
            else
            {
                printf("%s",s);
                printf("%s\n",t+x);
            }
        }
        else if(x>y)
        {
            printf("%s",s);
            printf("%s\n",t+x);
        }
        else
        {
            printf("%s",t);
            printf("%s\n",s+y);
        }
    }
    return 0;
}