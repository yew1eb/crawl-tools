#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct node
{
    node *next[10],*fail;
    int id;
    node()
    {
        memset(next,0,sizeof(next));
        fail=NULL;
        id=0;
    }
}*head;
vector<int> out;
char si[60005],temp[60005],pi[65];
bool flag;
void build(char *s,node *head,int id)
{
    int l=strlen(s),k;
    for(int i=0; i<l; ++i)
    {
        k=s[i]-'0';
        if(head->next[k]==NULL)
            head->next[k]=new node();
        head=head->next[k];
    }
    head->id=id;
}
void build_fail(node *head)
{
    node *now,*p;
    queue<node*> q;
    head->fail=NULL;
    q.push(head);
    for(; !q.empty();)
    {
        now=q.front();
        q.pop();
        for(int i=0; i<10; ++i)
            if(now->next[i])
            {
                p=now->fail;
                for(; p&&!p->next[i]; p=p->fail);
                now->next[i]->fail=p?p->next[i]:head;
                q.push(now->next[i]);
            }
    }
}
void ac_find(char *s,node *head)
{
    int len=strlen(s);
    node *p=head;
    for(int i=0;i<len;++i)
    {
        int k=s[i]-'0';
        for(;!p->next[k]&&p!=head;p=p->fail);
        p=p->next[k]==NULL?head:p->next[k];
        node *tmt=p;
        for(;tmt!=head;tmt=tmt->fail)
            if(tmt->id)
            {
               out.push_back(tmt->id);
               flag=false;
            }
    }
}
int main()
{
    int n,m,l;
    for(; ~scanf("%d%d",&m,&n);)
    {
        flag=true;
        head=new node();
        out.clear();
        for(int i=0;i<m;++i)
        {
            scanf("%s",temp);
            if(i==0)  strcpy(si,temp);
            else      strcat(si,temp);
        }
        for(int i=1; i<=n; ++i)
        {
            scanf("%s",pi);
            scanf("%s",pi);
            scanf("%d] %s",&l,pi);
            build(pi,head,i);
        }
        build_fail(head);
        ac_find(si,head);
        if(flag) puts("No key can be found !");
        else
        {
            printf("Found key:");
            for(int i=0;i<out.size();++i)
                printf(" [Key No. %d]",out[i]);
            printf("\n");
        }
    }
    return 0;
}
