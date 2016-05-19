#include<cstdio>
#include<cstring>
using namespace std;

const int kind = 26; //æå¤å°ç§å­ç¬¦
const int N = 1005;
const int M = 2000005;
struct node
{
    node *next[kind];
    node *fail;
    int id;//çæ¯ç¼å·
    node() {
        for(int i = 0; i < kind; i++)
            next[i] = NULL;
        fail = NULL;
        id = 0;
    }
}*q[51*N];
node *root;
int head, tail;
char source[M], s[M];
char vir[N][55];
int cnt[N];

void Insert(char *str, int id)
{
    node *p = root;
    int i = 0, index;
    while(str[i]) {
        index = str[i] - 'A';
        if(p->next[index] == NULL)
            p->next[index] = new node();
        p = p->next[index];
        i++;
    }
    p->id = id;
}
void build_ac_automation(node *root)
{
    root->fail = NULL;
    q[tail++] = root;
    node *p = NULL;
    while(head < tail) {
        node *temp = q[head++];
        for(int i = 0; i < kind; i++) {
            if(temp->next[i] != NULL) {
                if(temp == root) temp->next[i]->fail = root;
                else {
                    p = temp->fail;
                    while(p != NULL) {
                        if(p->next[i] != NULL) {
                            temp->next[i]->fail = p->next[i];
                            break;
                        }
                        p = p->fail;
                    }
                    if(p == NULL) temp->next[i]->fail = root;
                }
                q[tail++] = temp->next[i];
            }
        }
    }
}
void Query(char *str)
{
    int i = 0, index;
    node *p = root;
    while(str[i]) {
        index = str[i] - 'A';
        while(p->next[index] == NULL && p != root) p = p->fail;
        p = p->next[index];
        if(p == NULL) p = root;
        node *temp = p;
        while(temp != root && temp->id > 0) {
            cnt[temp->id]++;
            temp = temp->fail;
        }
        i++;
    }
}

int main()
{
    int n;
    while(~scanf("%d",&n)) {
        memset(cnt, 0, sizeof(cnt));
        head = tail = 0;
        root = new node();
      for(int i = 1; i <= n; i++) {
            scanf("%s", vir[i]);
            Insert(vir[i], i);
        }
        build_ac_automation(root);
        scanf("%s",source);
        int len = strlen(source);
        int l = 0;
        for(int i = 0; i <= len; i++) {
            if(source[i] >= 'A' && source[i] <= 'Z') //å ä¸ºçæ¯ä¸­åªæå¤§åå­æ¯ï¼æä»¥åªå¤çè¿ç»­çå¤§åå­æ¯ç»æçå­ç¬¦ä¸²
                s[l++] = source[i];
            else {
                s[l] = '\0';
                Query(s);
                l = 0;
            }
        }
        for(int i = 1; i <= n; i++)
            if(cnt[i])
                printf("%s: %d\n",vir[i], cnt[i]);
    }
    return 0;
}