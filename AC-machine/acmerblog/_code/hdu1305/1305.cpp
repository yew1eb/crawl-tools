#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstdlib>
#define lson l,mid,num<<1
#define rson mid+1,r,num<<1|1
using namespace std;
const int M=100005;
struct node
{
    int cnt;
    node *child[2];
    node()
    {
        cnt=0;
        for(int i=0; i<2; i++)
            child[i]=NULL;
    }
};
char a[15];
int flag;
node *root,*cur,*newnode;
void insert(char *a)
{
    cur=root;
    int len=strlen(a);
    for(int i=0; i<len ; i++)
    {
        int index=a[i]-'0';
        if(cur->child[index]!=NULL)
        {
            cur=cur->child[index];
            if(cur->cnt==1 || i==len-1)
            {
                flag=0;
                break;
            }
        }
        else
        {
            newnode=new node;
            cur->child[index]=newnode;
            cur=newnode;
        }
    }
    cur->cnt=1;
}
void del(node *head)
{
    for(int i=0; i<2; i++)
        if(head->child[i]!=NULL)
            del(head->child[i]);
    delete(head);
}
int main()
{
    int g=1;
    while(scanf("%s",a)!=EOF)
    {
        flag=1;
        root=new node;
        insert(a);
        while(scanf("%s",a)!=EOF)
        {
            if(strcmp(a,"9")==0)break;
            {
                if(!flag)
                    continue;
                insert(a);
            }
        }
        if(flag)printf("Set %d is immediately decodable\n",g++);
        else
            printf("Set %d is not immediately decodable\n",g++);
        del(root);
    }
    return 0;
}