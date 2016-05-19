#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
struct node
{
    int count;
    node *childs[2];
    node()
    {
        count=0;
        for(int i=0;i<2;i++)
        childs[i]=NULL;
    }
};
node *root,*current,*newnode;
int flag;
void insert(char *str)
{
    int i,m;
    current=root;
    for(i=0;i<strlen(str);i++)
    {
        m=str[i]-'0';
        if(current->childs[m]!=NULL)
        {
            current=current->childs[m];
            if(i==strlen(str)-1||current->count==1)
            {
                flag=0;
                break;
            }
        }
        else
        {
            newnode=new node;
            current->childs[m]=newnode;
            current=newnode;
        }
    }
    current->count=1;
}
void del(node *head)
{
    for(int i=0;i<2;i++)
    if(head->childs[i]!=NULL)
    del(head->childs[i]);
    delete(head);
}
int main()
{
    int cas=1;
    char str[15];
    while(scanf("%s",str)!=EOF)
    {
        flag=1;
        root=new node;
        insert(str);
        while(scanf("%s",str),strcmp(str,"9"))
        {
            if(!flag)
            continue;
            insert(str);
        }
        if(!flag)
        printf("Set %d is not immediately decodable\n",cas++);
        else
        printf("Set %d is immediately decodable\n",cas++);
        del(root);
    }
    return 0;
}
