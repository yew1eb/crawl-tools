#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef struct node
{
    int isword;
    char word[12];
    struct node *next[26];
    node()
    {
        isword = 0;
        memset(next, NULL, sizeof next );
    }
} *Tree, T;
Tree root = new node();

void insert(char *wd, char *s)
{
    int tmp;
    Tree p = root;
    while(*s)
    {
        tmp = *s - 'a';
        if(NULL == p->next[tmp])
        {
            p->next[tmp] = new node();
        }
        p = p->next[tmp];
        s++;
    }
    p->isword = 1;
    strcpy(p->word, wd);
}

char *find(char *s)
{
    int tmp;
    Tree p = root;
    while(*s)
    {
        int tmp = *s - 'a';
        if(NULL == p->next[tmp])
            return NULL;
        p = p->next[tmp];
        s++;
    }
    if(p->isword == 1)
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



