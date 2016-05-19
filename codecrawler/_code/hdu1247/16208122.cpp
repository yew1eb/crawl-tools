#include<stdio.h>
#include<string.h>
#include<malloc.h>
struct haha
{
    int cnt;
    struct haha *next[26];
}q,temp;
char str[50010][100];
struct haha *root;

struct haha *creat()
{
    int i;
    struct haha *p;
    p=(struct haha *)malloc(sizeof(struct haha));
    p->cnt=0;
    for(i=0;i<26;i++)
    {
        p->next[i]=NULL;
    }
    return p;
}
void insert(char *s)
{
    int d,i,pos;
        struct haha *p=root;
        d=strlen(s);
        for(i=0;i<d;i++)
        {
            pos=s[i]-'a';
            if(p->next[pos]==NULL)
            {
                p->next[pos]=creat();
                p=p->next[pos];
            }
            else
                p=p->next[pos];
        }
        p->cnt=1;
}
int find2(char *s)
{
    int i,pos,d;
    struct haha *p;
    p=root;
    d=strlen(s);
//    printf("d=%d \n",d);
    for(i=0;i<d;i++)
    {
        pos=s[i]-'a';
        if(p->next[pos]!=NULL)
        {
               p=p->next[pos];
             
        }
        else return 0;
    }
  if(p->cnt==1)
          return 1;
    return 0;

}
int find1(char *s)
{
    int i,pos,d;
    struct haha *p;
    p=root;
    d=strlen(s);
//    printf("d1=%d\n",d);
    for(i=0;i<d;i++)
    {
        pos=s[i]-'a';
        if(p->next[pos]!=NULL)
        {
            if(p->cnt==1) {if(find2(s+i)) return 1;}
            p=p->next[pos];
        }
        else return 0;
    }
    return 0;

}

int main()
{
    int i,count=0,t=6;
    root=creat();
    while(scanf("%s",str[count])!=EOF)
//    while(t--)
    {
    //    scanf("%s",str[count]);
        insert(str[count]);
        count++;
    }
    for(i=0;i<count;i++)
    {
        if(find1(str[i]))
            puts(str[i]);
    }
    return 0;
}