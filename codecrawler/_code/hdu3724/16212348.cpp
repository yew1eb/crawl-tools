#include<iostream>
#include<cstdio> 
#include<cstring>
using namespace std;

const int KIND = 26;
const int MAXN = 500000;
int cnt_node;
double width[8];

struct node{
    int cnt;
    node* next[KIND];
    void init(){
        cnt = 0;
        memset(next, 0, sizeof(next));
    }
}Heap[MAXN];

inline node* new_node(){
    Heap[cnt_node].init();
    return &Heap[cnt_node++];
}

void insert(node* root, char *str){
    for(char *p=str; *p; ++p){
        int ch=*p-'a';
        if(root->next[ch]==NULL)
            root->next[ch] = new_node();
        root = root->next[ch];
        ++root->cnt;
    }
}

int count(node* root, char *str){
    for(char *p=str; *p; ++p){
        int ch=*p-'a';
        if(root->next[ch]==NULL) 
            return 0;
        root=root->next[ch];
    }
    return root->cnt;
}

int main(){
    int n,m,q;
    char str[40];
    while(~scanf("%d%d",&n,&m)){
        // Trie tree init
        cnt_node=0;
        node *root = new_node();

        // word input
        for(int i=0; i<n; ++i){
            scanf("%s",str);
            insert(root, str);
        }

        int ans=0;
        while(m--){
            scanf("%d",&q);
            memset(str, 0, sizeof(str));
            int p=0;
            for(int k=0; k<q; ++k){
                double x;
                double sum=0;
                for(int i=0; i<8; ++i){
                    scanf("%lf",&width[i]);
                    sum += width[i];
                }
                sum /= 8.0;
                int ch=0;
                for(int i=7, d=1; i>=0; --i){
                    if(width[i] > sum){
                        ch |= d;
                    }
                    d <<= 1;
                }
                if(ch>='a' && ch<='z')
                    str[p++] = (char)ch;
            }
            ans += count(root, str);
        }
        printf("%d\n",ans);
    }
    return 0;
}