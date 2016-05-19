#include<stdio.h>
#include<string.h>
#include<stdlib.h>
bool is_phone;/*å¤æ­æ¯å¦è½æåæ¨æå·ç */
struct node
{
    bool flag;/*å¨æ°å­ä¸²æåæ è®°*/
    struct node *next[10];
};
struct node *root;
struct node *newset()/*æ°å»ºç»ç¹*/
{
    struct node *p=(struct node *)malloc(sizeof(struct node));
    for(int i=0;i<10;i++)
    {
        p->next[i]=NULL;
    }
    p->flag=false;/*åå§åä¸ºfalse*/
    return p;
}
void insert(char *str)/*å»ºç«å­å¸æ */
{
    struct node *p;
    p=root;
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {
        if(p->next[str[i]-'0']==NULL)/*å¦æä»¥åæ²¡æå»ºç«è¿è¯¥ç»ç¹*/
        {
           if(p->flag==false)
           {
               p->next[str[i]-'0']=newset();/*å»ºç«æ°ç»ç¹*/
               p=p->next[str[i]-'0'];
               if(i==len-1)/*åªæå½æåå°æ°å­ä¸²æ«å°¾æ¶ï¼æ è®°ç»ç¹ä¸ºtrue;*/
               {
                   p->flag=true;
               }
               else
               {
                   p->flag=false;
               }
           }
           else/*å¦åè¯´æå½åå»ºç«çæ°å­ä¸²è¦çäºä»¥åçæ°å­ä¸²ï¼å½åæ´é¿ï¼ï¼ä¸è½æ¨æå·ç */
           {
               is_phone=false;
               return ;
               
           }
        }
        else
        {
            if(i==len-1&&p->flag==false)/*å¦æå½åå·ç æ¯ä»¥ååºç°è¿çå·ç çåç¼ï¼å½åæ´ç­ï¼*/
            {
                is_phone=false;
                return ;
            }
            p=p->next[str[i]-'0'];
        }
    }
    return ;
}
int del(node *t)/*éæ¾åå­*/
{
    if(t==NULL) return 0;
    for(int i=0;i<10;i++)
    {
        if(t->next[i]!=NULL)
        {
            del(t->next[i]);
        }
    }
    free(t);
    return 0;
}
int main()
{
    int ncase,n;
    char str[1001];
    scanf("%d", &ncase);
    while(ncase--)
    {
        root=newset();
        scanf("%d",&n);
        is_phone=true;
        for(int i=0;i<n;i++)
        {
            scanf("%s",str);
            insert(str);
        }
        if(is_phone) printf("YES\n");
        else printf("NO\n");
        del(root);
    }
    return 0;
}        