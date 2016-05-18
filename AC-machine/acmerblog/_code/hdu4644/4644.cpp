#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define maxn 100186
using namespace std;

struct node
{
    char ch;
    int index;
    bool operator < (const node & cmp)const
    {
        return ch<cmp.ch;
    }
}save[maxn];
char t[maxn];
char str[maxn],txt[maxn];
int next[maxn];

void getnext(int len)
{
    next[0]=0;next[1]=0;
    for(int i=1;i<len;i++)
    {
        int j=next[i];
        while(j && txt[j]!=txt[i])j=next[j];
        next[i+1]=txt[j]==txt[i]?j+1:0;
    }
}

void find(int n,int m)
{
    int j=0;
    for(int i=0;i<n;i++)
    {
        while(j&&txt[j]!=str[i])j=next[j];
        if(txt[j]==str[i])j++;
        if(j==m){printf("YES\n");return ;}
    }
    printf("NO\n");
}

int main()
{
    while(scanf("%s",t)!=EOF)
    {
        int len=strlen(t);
        for(int i=0;i<len;i++)
        {
            save[i].ch=t[i];
            save[i].index=i;
        }

        stable_sort(save,save+len);

        int now=save[0].index;
        for(int i=0;i<len-1;i++)
        {
            str[i]=save[now].ch;
            now=save[now].index;
        }

        int q;
        scanf("%d",&q);
        while(q--)
        {
            scanf("%s",txt);
            int m=strlen(txt);
            getnext(m);

            find(len-1,m);
        }
    }
    return 0;
}
