#include <iostream>
#include <string.h>
using namespace std;
int n,ans[1000];
typedef struct Binary_Tree
{
    int value;
    struct Binary_Tree *lchild,*rchild;
    Binary_Tree()
    {
        value=0;
        lchild=rchild=NULL;
    }
}BTree;
bool Add(BTree *&root,char *s,int value) //åå»ºäºåæ 
{
    if (root==NULL)
    {
        root=new BTree();
    }
    if(*s=='\0')
    {
        if(root->value!=0)
        {
            return false;
        }
        root->value=value;
        return true;
    }
    if (*s=='L')
    {
        return Add(root->lchild, s+1, value);
    }
    else if(*s=='R')
    {
        return Add(root->rchild, s+1, value);
    }
    return false;
}
void Delete(BTree *&root) //å é¤äºåæ 
{
    if (root==NULL)
    {
        return;
    }
    Delete(root->lchild);
    Delete(root->rchild);
    delete root;
}
bool bfs(BTree *root) //å±æ¬¡éå
{
    BTree *q[1000];
    int front=0;
    int rear=1;
    q[0]=root;
    n=0;
    while (front<rear)
    {
        BTree *temp=q[front++];
        if(!temp->value)
        {
            return false;
        }
        ans[n++]=temp->value;
        if(temp->lchild)
        {
            q[rear++]=temp->lchild;
        }
        if(temp->rchild)
        {
            q[rear++]=temp->rchild;
        }
    }
    return true;
}

int main()
{
    
    BTree *Root=NULL; //æ³¨æåå§å
    char s[1000];
    bool flag;
    while (1)
    {
        flag=true;
        Delete(Root);
        Root=NULL; //æ³¨æéè¦éæ°ç½®ç©º
        while (1)
        {
            if(scanf("%s",s)==EOF)
            {
                return 0;
            }
            if(strcmp(s, "()")==0)
            {
                break;
            }
            int v;
            sscanf(&s[1], "%d",&v);
            char *S=strchr(s, ',');
            S=++S;
            S[strlen(S)-1]='\0';
            if(!Add(Root,S, v))
            {
                flag=false;
            }
        }
        if(!flag)
        {
            printf("not complete\n");
        }
        else
        {
            if(!bfs(Root))
            {
                printf("not complete\n");
            }
            else
            {
                for(int i = 0; i < n-1; i++)
                {
                    printf("%d ", ans[i]);
                }
                printf("%d\n",ans[n-1]);

            }
        }
    }
}