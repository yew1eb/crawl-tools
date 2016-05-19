#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxn=1000010;
char s1[maxn],s2[maxn];
int next[maxn];

void get_next(char *s,int len)
{
    next[0]=-1;
    int i=0,j=-1;
    while(i<len)
    {
        if(j==-1||s[i]==s[j]) next[++i]=++j;
        else j=next[j];
    }
}
int kmp(char *t1,char *t2)
{
    int len1=strlen(t1);
    int len2=strlen(t2);
    get_next(t2,len2);
    int i=0,j=0;
    while(i<len1&&j<len2)
    {
        if(j==-1||t1[i]==t2[j]) ++i,++j;
        else j=next[j];
    }
    return j;
}

int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%s %s",s1,s2);
        int l1=kmp(s1,s2);
        int l2=kmp(s2,s1);
        printf("%d\n",strlen(s1)+strlen(s2)-max(l1,l2));
    }
    return 0;
}