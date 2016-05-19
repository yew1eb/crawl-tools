#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int tree1[10000];
int tree2[10000];
void Insert(char word,int *tree)
{
    int now=1;
    int c=word-'0';
    while(tree[now]!=-1)
    {
        if(tree[now]<c)
            now=now*2+1;
        else
            now=now*2;
    }
    tree[now]=c;
}
void build(char *str,int *tree)
{
    int l=strlen(str);
    int i=1;
    tree[1]=str[0]-'0';
    for(i=1;i<l;i++)
    {
        Insert(str[i],tree);
    }
}
int main()
{
    int n;
    char str[1000];
    while(scanf("%d",&n),n!=0)
    {
        memset(tree1,-1,sizeof(tree1));
        memset(tree2,-1,sizeof(tree2));
        scanf("%s",str);
        build(str,tree1);
        int i;
        for(i=0;i<n;i++)
        {
            memset(tree2,-1,sizeof(tree2));
            scanf("%s",str);
            build(str,tree2);
            int j;
            for(j=0;j<5000;j++)
            {
                if(tree1[j]!=tree2[j])
                    break;
            }
            if(j==5000)
                printf("YES\n");
            else
                printf("NO\n");
        }

    }
    return 0;
}
