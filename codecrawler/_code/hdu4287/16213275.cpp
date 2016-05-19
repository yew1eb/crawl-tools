#include<stdio.h>
#include<string.h>
int hash[128];
struct TrieNode{
    int no;//å¯¹åºçæ°å­ä¸²çç¼å·ï¼è¿ä¸ªç¼å·å©äºåé¢å¯¹åºç°æ¬¡æ°è¿è¡ç»è®¡
    TrieNode *next[10];
}node[30005];
TrieNode *root = &node[0];
int cnt,result[5005];
char word[10],s[10];
void init()
{
    //æ¯ä¸ªå­æ¯å¯¹åºçæ°å­
    hash['a']=hash['b']=hash['c']=2;
    hash['d']=hash['e']=hash['f']=3;
    hash['g']=hash['h']=hash['i']=4;
    hash['j']=hash['k']=hash['l']=5;
    hash['m']=hash['n']=hash['o']=6;
    hash['p']=hash['q']=hash['r']=hash['s']=7;
    hash['t']=hash['u']=hash['v']=8;
    hash['w']=hash['x']=hash['y']=hash['z']=9;
}
void initRoot()
{
    int i;
    for(i=0;i<10;i++)
    {
        root->next[i]=NULL;
    }
}
//åå­å¸æ ä¸­æå¥æ°çä¸²ã
void insert(char str[],int num)
{
    TrieNode *p = root;
    int len=strlen(str),i,j;
    for(i=0;i<len;i++)
    {
        if(p->next[str[i]-'0']==NULL)
        {
            p->next[str[i]-'0']=&node[cnt];
            for(j=0;j<10;j++)node[cnt].next[j]=NULL;
            node[cnt].no=-1;
            cnt++;
        }
        p=p->next[str[i]-'0'];
    }
    //è®¾ç½®æ°å­ä¸²å¯¹åºçç¼å·
    p->no=num;
}
/** æ¥è¯¢ä¸ä¸ªå­æ¯å­ç¬¦ä¸²å¯¹åºçæ°å­ä¸² */
void query(char str[])
{
    int len=strlen(str),i;
    TrieNode *p=root;
    for(i=0;i<len;i++)
    {
        p=p->next[hash[str[i]]];
        if(p==NULL)break;
    }
    if(p==NULL)return;//è¯¥ä¸²å¯¹åºçæ°å­ä¸²ä¸å­å¨ã
    else{
        if(p->no!=-1)result[p->no]++;
    }
}
int main()
{
    int t,m,n,i;
    scanf("%d",&t);
    init();
    while(t--)
    {
        cnt=1;
        initRoot();
        memset(result,0,sizeof(result));
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%s",word);
            insert(word,i);
        }
        for(i=0;i<m;i++)
        {
            scanf("%s",s);
            query(s);
        }
        for(i=0;i<n;i++)
        {
            //é¡ºåºæåºæ¯ä¸ªä¸²åºç°çæ¬¡æ°ã
            printf("%d\n",result[i]);
        }
    }
    return 0;
}