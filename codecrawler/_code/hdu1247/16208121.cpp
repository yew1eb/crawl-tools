#include"stdio.h"
#include"stdlib.h"
#include"string.h"


struct dictree
{
    struct dictree *child[26];
    int flag;
};
struct dictree *root;


char str[50011][50];


void insert(char *source)
{
    int i,j;
    int len;
    struct dictree *current,*newnode;


    len=strlen(source);
    current=root;


    for(i=0;i<len;i++)
    {
        if(current->child[source[i]-'a']!=0)
            current=current->child[source[i]-'a'];
        else
        {
            newnode=(struct dictree *)malloc(sizeof(struct dictree));
            for(j=0;j<26;j++)    newnode->child[j]=0;
            newnode->flag=0;
            current->child[source[i]-'a']=newnode;
            current=newnode;
        }
    }


    current->flag=1;
}


int find(char *source)
{
    int i;
    int len;
    struct dictree *current;


    len=strlen(source);
    current=root;
    for(i=0;i<len;i++)
    {
        if(current->child[source[i]-'a']!=0)
            current=current->child[source[i]-'a'];
        else    return 0;
    }


    return current->flag;
}


int main()
{
    char t1[50],t2[50];
    int t;
    int k;
    int i,l,j,j2;
    int len;
    int hash[50011];


    root=(struct dictree *)malloc(sizeof(struct dictree));
    for(j=0;j<26;j++)    root->child[j]=0;
    root->flag=0;


    k=0;
    while(scanf("%s",str[k])!=-1)
    {
        insert(str[k]);
        k++;
    }


    for(i=0;i<k;i++)
    {
        len=strlen(str[i]);
        hash[i]=0;


        if(len==1)    continue;
        
        t=len-1;
        for(l=1;l<=t;l++)
        {
            for(j=0;j<l;j++)        t1[j]=str[i][j];
            t1[j]=0;
            for(j2=0;j<len;j++,j2++)t2[j2]=str[i][j];
            t2[j2]=0;

            if(find(t1)&&find(t2))    {hash[i]=1;break;}
        }
    }


    for(i=0;i<k;i++)    if(hash[i])    printf("%s\n",str[i]);


    return 0;
}