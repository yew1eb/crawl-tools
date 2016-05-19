#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct node
{
    int count;
    node *next[10];
    node():count(0){memset(next,0,sizeof(next));}
};
node *root;
node *b[10003];
int k=0;
void insert(char *a)
{
    int l=strlen(a);
    node *p=root;
    int i;
    for(i=0;i<l;i++)
    {
        if(p->next[a[i]-'0']==0)
        {
            p->next[a[i]-'0']=new node;
        }
        p=p->next[a[i]-'0'];
        p->count++;
    }
    b[k++]=p;
}
int check(int n)
{
    int i;
    for(i=0;i<k;i++)
    {
        if(b[i]->count!=1)
            return 1;
    }
    return 0;
}
void de(node *p)
{
    if(p==0)
        return ;
    int i;
    for(i=0;i<10;i++)
    {
        de(p->next[i]);
    }
    delete p;

}
int main()
{
    int t;
    scanf("%d",&t);
    char a[15];
    while(t--)
    {
        root = new node;
        int n;
        k=0;
        scanf("%d",&n);
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%s",a);
            insert(a);
        }
        if(check(n))
            printf("NO\n");
        else
            printf("YES\n");
        de(root);
    }
    return 0;
}