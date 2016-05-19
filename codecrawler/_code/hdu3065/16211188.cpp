#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
struct node
{
    node *next[26],*fail;
    int id;
    node()
    {
        memset(next,0,sizeof(next));
        fail=NULL;
        id=0;
    }
}*head;
struct code
{
    string virus;
    int times;
}temp;
map<int,code> mapt;
map<int,string> maps;
void build(char *x,node *head,int id)
{
    //printf("build\n");
    int l=strlen(x);
    for(int i=0; i<l; ++i)
    {
        int k=x[i]-'A';
        if(head->next[k]==NULL)
            head->next[k]=new node();
        head=head->next[k];
    }
    head->id=id;
}
void build_fail(node *head)
{
    //printf("build_fail\n");
    node *now,*p;
    queue<node*> q;
    head->fail=NULL;
    q.push(head);
    for(; !q.empty();)
    {
        now=q.front();
        q.pop();
        for(int i=0; i<26; ++i)
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
    //printf("ac_find %s\n",s);
    int len=strlen(s);
    node *p=head;
    for(int i=0;i<len;++i)
    {
        if(s[i]<'A'||'Z'<s[i])
        {
            p=head;//è¿å¥ä¸è½å°
            continue;
        }
        int k=s[i]-'A';
        for(;p->next[k]==NULL&&p!=head;p=p->fail);
        p=p->next[k]==NULL?head:p->next[k];
        node *tmp=p;
        for(;tmp!=head;)
        {
            if(tmp->id)
            {
                if(mapt.count(tmp->id))
                {
                    mapt.find(tmp->id)->second.times++;
                }
                else
                {
                    temp.times=1;
                    temp.virus=string(maps.find(tmp->id)->second);
                    mapt.insert(make_pair(tmp->id,temp));
                }
            }
            tmp=tmp->fail;
        }
    }
}
char t[55],s[2000005];
int main()
{
    int n;
    for(; ~scanf("%d",&n);)
    {
        mapt.clear();
        maps.clear();
        head=new node();
        for(int i=1; i<=n; ++i)
        {
            scanf("%s",t);
            maps.insert(make_pair(i,string(t)));
            build(t,head,i);
        }
        build_fail(head);
        scanf("%s",s);
        ac_find(s,head);
        for(map<int,code>::iterator it=mapt.begin();it!=mapt.end();++it)
            printf("%s: %d\n",it->second.virus.c_str(),it->second.times);
    }
    return 0;
}
