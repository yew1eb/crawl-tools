#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<map>
using namespace std;

map<int,bool>mp;

const int maxn=1000000+10;
const int prime=14997;
int a[maxn],b[maxn];



typedef struct Node
{
    int key;
    struct Node *next;
}node,*listnode;

listnode table[prime];

void init()
{
    for(int i=0;i<prime;i++)
    {
        table[i]=(listnode)malloc(sizeof(node));
        table[i]->next=NULL;
    }
}

inline int ReadInt()//ä¼åæ¥åintæ°ï¼çæ¶é´ï¼å·ä½åå®¹èªå·±çæï¼å½ææ¨¡æ¿ä½¿ç¨
{
    char ch = getchar();
    int data = 0;
    while (ch < '0' || ch > '9')
        ch = getchar();
    do
    {
        data = data*10 + ch-'0';
        ch = getchar();
    }while (ch >= '0' && ch <= '9');
    return data;
}

void inSert(int real_val,int val)
{
    listnode p,New;
    p=table[val];
    New=(listnode)malloc(sizeof(node));
    New->key=real_val;
    New->next=p->next;
    p->next=New;
}

int Search(int mod,int x)
{
    listnode p;
    p=table[mod]->next;
    int sum=0;
    while(p!=NULL)
    {
       if(p->key==x)
       {
           p->key=0;
           sum++;
       }
       p=p->next;
    }
    return sum;
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i=1;i<=n;i++)
        {
            a[i]=ReadInt();
            int Hashval=a[i]%prime;
            inSert(a[i],Hashval);
        }
        mp.clear();
        for(int i=1;i<=m;i++)
        {
            int x=ReadInt();
            if(mp[x])
            {
                printf("0\n");
                continue;
            }
            int mod=x%prime;
            mp[x]=true;
            printf("%d\n",Search(mod,x));
        }
    }
    return 0;
}