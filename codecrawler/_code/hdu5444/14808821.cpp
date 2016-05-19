#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

void ins(Node **root, int x)
{
    if( *root == NULL) {
        Node *New = (Node *)malloc(sizeof(Node));
        New->data = x;
        New->left = New->right = NULL;
        *root = New;
        //printf("%p, %d\n", root, (*root)->data);
    }else if( (*root)->data > x) {
        ins( &(*root)->right, x);
    }else if( (*root)->data < x) {
        ins( &(*root)->left, x);
    }
}

void print(Node* root)
{
    if( root == NULL) {
        NULL;
    }else {
        print(root->right);
        printf("%d\n", root->data);
        print(root->left);
    }
}

void fin(Node **root, int x)
{
    if( *root == NULL || (*root)->data == x) {
        return ;
    }
    if( (*root)->data > x) {
        putchar('E');
        fin( &(*root)->right, x);
    }else {
        putchar('W');
        fin( &(*root)->left, x);
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    int x, q, n;
    while(T--)
    {
        scanf("%d",& n);
        Node * head = NULL;
        while(n--) {
            scanf("%d", &x);
            ins(&head, x);
        }
        //print(head);
        scanf("%d", &q);
        while(q--) {
            scanf("%d", &x);
            fin(&head, x);
            puts("");
        }
    }
    return 0;
}
