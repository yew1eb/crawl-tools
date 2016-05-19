#include"iostream"
#include"cstdio"
#include"cstring"
using namespace std;
const int kind=26;
const int N=10011;
const int M=1000011;

struct node
{
    node *child[kind];
    node *fail;
    int count;
    void init()
    {
        int l;
        for(l=0;l<kind;l++)    child[l]=NULL;
        count=0;
        fail=NULL;
    }
}*q[50*N];
node *root;
int head,tail;

void insert(char *str)
{
    node *now,*next;
    int i=0,t;
    now=root;
    while(str[i])
    {
        t=str[i]-'a';
        if(now->child[t]!=NULL)    now=now->child[t];
        else
        {
            next=new node;
            next->init();
            now->child[t]=next;
            now=next;
        }
        i++;
    }
    now->count++;
}

void build_fail()
{
    int l;
    node *now,*p;

    head=tail=0;
    now=root;
    q[tail++]=now;

    while(head<tail)
    {
        now=q[head];
        for(l=0;l<kind;l++)
        {
            if(now->child[l]==NULL)    continue;
            if(now==root)    now->child[l]->fail=root;
            else
            {
                p=now->fail;
                while(p!=NULL)
                {
                    if(p->child[l]!=NULL)
                    {
                        now->child[l]->fail=p->child[l];
                        break;
                    }
                    p=p->fail;
                }
                if(p==NULL)    now->child[l]->fail=root;
            }
            q[tail++]=now->child[l];
        }
        head++;
    }
}

int query(char *str)
{
    node *now,*temp;
    int i,t,cnt;
    i=cnt=0;
    now=root;
    while(str[i])
    {
        t=str[i]-'a';
        while(now->child[t]==NULL && now!=root)    now=now->fail;
        now=now->child[t];
        if(now==NULL)    now=root;
        temp=now;
        while(temp!=NULL && temp->count!=-1)        //count+1æ¯éå¯¹è¿ä¸ªé¢çå°ä¼å
        {
            cnt+=temp->count;                        //ç±äºæ¯ä¸ªåè¯å¨str2ä¸­éå¤åºç°ä¹åªè½è®©cnt+1ï¼æä»¥ä½¿ç¨è¿åè¦æ è®°ä¸ä¸ä»¥åéå¤çç»cntå ã
            temp->count=-1;
            temp=temp->fail;
        }
        i++;
    }
    return cnt;
}

int main()
{
    int T;
    int n;
    char str1[55],str2[M];
    cin>>T;
    while(T--)
    {
        cin>>n;
        root=new node;
        root->init();
        while(n--)    {scanf("%s",str1);insert(str1);}

        build_fail();

        scanf("%s",str2);
        printf("%d\n",query(str2));
    }
    return 0;
}