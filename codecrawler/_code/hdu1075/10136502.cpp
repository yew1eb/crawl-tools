#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct node{
    node *next[26];
    int h;
    char word[12];
    node()
    {
        h=0;
        memset(next,0,sizeof(next));
    }
}*Tree,T;
Tree root=new node();

void insert(char *eng,char *mar)
{
    Tree p=root;
    while(*mar)
    {
        int id=*mar-'a';
        if(p->next[id]==NULL)
            p->next[id]=new node();
        p=p->next[id];
        mar++;
    }
    p->h=1;
    strcpy(p->word,eng);
}
char *find(char *str)
{
    Tree p=root;
    while(*str)
    {
        int id=*str-'a';
        if(p->next[id]==NULL)
            break;
        p=p->next[id];
        str++;
    }
    if(*str==NULL && p->h==1)
        return p->word;
    else
        return NULL;
}

int main()
{
    int i,k,len;
    char a[12],b[12],tmp[3005],tp[3005];
    char *p;
    scanf("%s",a);
    while(scanf("%s",a) && strcmp(a,"END")!=0)
    {
        scanf("%s",b);
        insert(a,b);
    }

    scanf("%s",a);
    getchar();
    k=0;
    while(gets(tmp),strcmp(tmp,"END"))
    {
        len=strlen(tmp);
        tmp[len++]=' ';
        tmp[len]=0;
        for(i=0;i<len;i++)
        {
            if(!islower(tmp[i]))
            {
                tp[k]=0;
                k=0;
                p=find(tp);
                if(p)
                    printf("%s",p);
                else
                    printf("%s",tp);
                if(i!=len-1)
                    putchar(tmp[i]);
            }
            else
                tp[k++]=tmp[i];
        }
        puts("");
    }
    return 0;
}