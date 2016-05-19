#include <stdio.h>
#include <string.h>

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
    char word[12], a[12], b[12];
    char str[3100], *p;
    int i, j, k, len;
    //freopen("d:\\in.txt","r",stdin);
    scanf("%s",a);
    while(scanf("%s",a)&&strcmp(a,"END")!=0)
    {
        scanf("%s",b);
        insert(a,b);
    }
    scanf("%s",a);
    getchar();
    while(gets(str)&&strcmp(str,"END")!=0)
    {
        len = strlen(str);
        for(i=0; i<len; ++i)
        {
            if(str[i]>='a' && str[i]<='z')
            {
                j = i;
                while(j<len&&str[j]>='a'&&str[j]<='z') j++;
                k = 0;
                for(int p=i; p<j; ++p)
                {
                    word[k++] = str[p];
                }
                i = j-1;
                word[k] ='\0';
                p = find(word);
                if(p)
                    printf("%s",p);
                else
                    printf("%s",word);

            }
            else
            {
               printf("%c",str[i]);
            }
        }
        puts("");
    }
    return 0;
}
