#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

#define mst(a,b) memset(a,b,sizeof(a))
#define eps 10e-8

const int MAX_ = 10010;
const int MAX = 10;
const int N = 100010;
const int INF = 0x7fffffff;

typedef struct Node{
    int isStr;

    struct Node *next[MAX];

    Node():isStr(0){
        memset(next, NULL, sizeof(next));
    }
    ~Node(){
        for(int i = 0;i < MAX; ++i)
            if(next[i] != NULL)
                delete next[i];
    }
}TrieNode,*Trie;

Trie root;



int Insert(char *s){
    bool flag = false;
    TrieNode *p = root,*q;
    while(*s){
        if(p ->next[*s-'0'] == NULL){
            q = new TrieNode;
            p ->next[*s-'0'] = q;
            flag = true;
        }
        if(p->isStr == 1){
            return 0;
        }
        p = p ->next[*s-'0'];
        s++;
    }
    p->isStr = 1;
    if(!flag)return 0;
    return 1;
}

int main() {
    char s[MAX*10], str[MAX*10];
    int ans, cnt, len;
    bool flag;
    flag = true;cnt = 1;
    root = new TrieNode;
    //ans = 0;flag = false;cnt = 0;
    while(scanf("%s",s)!=EOF){
        if(s[0] == '9'){
            if(!flag){
                printf("Set %d is not immediately decodable\n",cnt++);
            }
            else printf("Set %d is immediately decodable\n",cnt++);

            flag = true;
            delete root;
            root = new TrieNode;
            continue;
        }
        if(flag)
            flag = Insert(s);
    }

}
