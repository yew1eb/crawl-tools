#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct node
{
    int num;
    char str[15];
    node* next[29];
    node():num(0){memset(next,0,sizeof(next));}
};
node *root;
char book[3005];
void Insert(char *a,char *b)
{
    int l=strlen(a);
    int i;
    node *p=root;
    for(i=0;i<l;i++)
    {
        if(p->next[a[i]-'a']==0)
        {
            node *q=new node;
            p->next[a[i]-'a']=q;
        }
        p=p->next[a[i]-'a'];
    }
    p->num=1;
    strcpy(p->str,b);
}
char * Find(char *a)
{
    int l=strlen(a);
    node *p=root;
    for(int i=0;i<l;i++)
    {
        p=p->next[a[i]-'a'];
        if(p==0)
            return NULL;
    }
    if(p->num==1)
        return p->str;
    else
        return NULL;
}
int main()
{
    char a[15],b[15];
    root=new node;
    scanf("%s",a);
    while(scanf("%s",a),strcmp(a,"END"))
    {
        scanf("%s",b);
        Insert(b,a);
    }
    scanf("%s",a);
    getchar();
    while(gets(book),strcmp(book,"END"))
    {
        int l=strlen(book);
        int i,k=0;
        for(i=0;i<l;i++)
        {
            while(book[i]>='a'&&book[i]<='z')
            {
                b[k++]=book[i];
                i++;
            }
            b[k]='\0';
            char* j=Find(b);
            if(j!=0)
                printf("%s",j);
            else
                printf("%s",b);
            printf("%c",book[i]);
            k=0;
        }
        printf("\n");
    }
    return 0;
}
