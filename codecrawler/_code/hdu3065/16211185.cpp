/*******************************************************
é¢ç®å¤§æï¼
ç»å¤ä¸²çæ¯åä¸ä¸ªæºç ;
æ±æ¯ä¸²çæ¯å¨æºç ä¸­åºç°çæ¬¡æ°;

ç®æ³ææ³ï¼
ACèªå¨æº;
ç»æ¯ä¸²çæ¯ä¸ä¸ªç¼å·;
å½å¹éæååç¨visitæ°ç»è®°å½è¯¥çæ¯åºç°çæ¬¡æ°;
********************************************************/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int K=27;
const int C=55;
const int N=1010;
const int M=2000010;

int visit[N];

struct node
{
    node *fail; //å¤±è´¥æé ãã
    node *next[K]; //Tireæ¯ä¸ªèç¹ç26ä¸ªå­èç¹ï¼æå¤26ä¸ªå­æ¯ï¼ ãã
    int count; //ç¨æ¥è®°å½çæ¯çç¼å·ãã
    node()//æé å½æ°åå§å ãã
    {
        fail=NULL;
        count=-1;
        memset(next,NULL,sizeof(next));
    }
}*q[M]; //éåï¼æ¹ä¾¿ç¨äºbfsæé å¤±è´¥æé ã

char a[N][C]; //è¾å¥çåè¯ ãã
char str[M]; //æ¨¡å¼ä¸² ãã
int head,tail; //éåçå¤´å°¾æé ã

void insert(char *str,node *&root,int x)//å»ºç«Trie
{
    if (root==NULL)
        root=new node;
    node *p=root;
    int len=strlen(str);
    for(int i=0; i<len; ++i)
    {
        int temp=str[i]-'A';
        if(p->next[temp]==NULL)
            p->next[temp]=new node();
        p=p->next[temp];
    }
    p->count=x;
}

void build_ac_automation(node *root)//åå§åfailæéï¼BFS
{
    root->fail=NULL;
    q[head++]=root;//å¼¹åºéå¤´
    while(head!=tail)
    {
        node *temp=q[tail++];
        node *p=NULL;
        for(int i=0; i<K; i++)
        {
            if(temp->next[i])
            {
                if(temp==root)//ç¬¬ä¸ä¸ªåç´ failå¿æåæ ¹
                    temp->next[i]->fail=root;
                else
                {
                    p=temp->fail;//å¤±è´¥æé
                    while(p)//2ç§æåµç»æï¼å¹éä¸ºç©ºoræ¾å°å¹é
                    {
                        if(p->next[i])//æ¾å°å¹é
                        {
                            temp->next[i]->fail=p->next[i];
                            break;
                        }
                        p=p->fail;
                    }
                    if(p==NULL)//ä¸ºç©ºåä»å¤´å¹é
                        temp->next[i]->fail=root;
                }
                q[head++]=temp->next[i];//å¥é
            }
        }
    }
}

void query(node *root,char *str)//æ«æ
{
    node *p=root;//Tireå¥å£
    int len=strlen(str);
    for(int i=0; i<len; i++)
    {
        int index=str[i]-'A';
        if(str[i]<'A'||str[i]>'Z')//åºç°éå¤§åå­æ¯
            index=26;
        while(p->next[index]==NULL&&p!=root)//è·³è½¬å¤±è´¥æé
            p=p->fail;
        p=p->next[index];
        if(p==NULL)
            p=root;
        node *temp=p;//pä¸å¨ï¼tempè®¡ç®åç¼ä¸²
        while(temp!=root)
        {
            if(temp->count>-1)//å½æåºç°çæ¯æ¶ä¸ç®¡ä¹åææ²¡æåºç°è¿é½è¦ç´¯å 
                visit[temp->count]++;
            temp=temp->fail;
        }
    }
}

int main()
{
    //freopen("C:\\Users\\Administrator\\Desktop\\kd.txt","r",stdin);
    int n;
    while(~scanf("%d",&n))
    {
        memset(visit,0,sizeof(visit));
        head=tail=0;
        node *root=NULL;
        for(int i=0; i<n; i++)
        {
            scanf("%s",a[i]);
            insert(a[i],root,i);
        }
        build_ac_automation(root);
        scanf("%s",str);
        query(root,str);
        for(int i=0; i<n; i++)
        {
            if(visit[i])
                printf("%s: %d\n", a[i], visit[i]);
        }
    }
    return 0;
}
