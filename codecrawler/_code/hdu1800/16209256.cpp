#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;
struct node
{
    int count;
    node *next[15];
    node():count(0)
    {
        memset(next,0,sizeof(next));
    }
};
node *root;
int maxx;
void insert(char *str)
{
    int l=strlen(str);
    int i;
    node *p=root;
    for(i=0;i<l;i++)
    {
        if(p->next[str[i]-'0']==0)
            p->next[str[i]-'0']=new node;
        p=p->next[str[i]-'0'];
    }
    p->count++;
}
void travel(node *p)
{
    if(p->count>maxx)
        maxx=p->count;
    int i;
    for(i=0;i<=9;i++)
    {
        if(p->next[i])
            travel(p->next[i]);
    }
}
void de(node *p)
{
    int i;
    for(i=0;i<10;i++)
        if(p->next[i])
            de(p->next[i]);
    delete p;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i;
        maxx=0;
        root =new node;
        char str[35];
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            int j;
            for(j=0;j<(int)strlen(str);j++)
                if(str[j]!='0')
                    break;
            insert(str+j);
        }
        travel(root);
        printf("%d\n",maxx);
        de(root);
    }
    return 0;
}
