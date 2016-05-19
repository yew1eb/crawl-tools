#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
#define N 500010
char str[1000010], keyword[51];
int head, tail;

struct node
{
    node *fail;
    node *next[26];
    int count;
    node() //init
    {
        fail = NULL;
        count = 0;
        for(int i = 0; i < 26; ++i)
            next[i] = NULL;
    }
}*q[N];
node *root;

void insert(char *str) //å»ºç«Trie
{
    int temp, len;
    node *p = root;
    len = strlen(str);
    for(int i = 0; i < len; ++i)
    {
        temp = str[i] - 'a';
        if(p->next[temp] == NULL)
            p->next[temp] = new node();
        p = p->next[temp];
    }
    p->count++;
}

void build_ac() //åå§åfailæéï¼BFS
{
    q[tail++] = root;
    while(head != tail)
    {
        node *p = q[head++]; //å¼¹åºéå¤´
        node *temp = NULL;
        for(int i = 0; i < 26; ++i)
        {
            if(p->next[i] != NULL)
            {
                if(p == root) //ç¬¬ä¸ä¸ªåç´ failå¿æåæ ¹
                    p->next[i]->fail = root;
                else
                {
                    temp = p->fail; //å¤±è´¥æé
                    while(temp != NULL) //2ç§æåµç»æï¼å¹éä¸ºç©ºoræ¾å°å¹é
                    {
                        if(temp->next[i] != NULL) //æ¾å°å¹é
                        {
                            p->next[i]->fail = temp->next[i];
                            break;
                        }
                        temp = temp->fail;
                    }
                    if(temp == NULL) //ä¸ºç©ºåä»å¤´å¹é
                        p->next[i]->fail = root;
                }
                q[tail++] = p->next[i]; //å¥é
            }
        }
    }
}

int query() //æ«æ
{
    int index, len, result;
    node *p = root; //Tireå¥å£
    result = 0;
    len = strlen(str);
    for(int i = 0; i < len; ++i)
    {
        index = str[i] - 'a';
        while(p->next[index] == NULL && p != root) //è·³è½¬å¤±è´¥æé
            p = p->fail;
        p = p->next[index];
        if(p == NULL)
            p = root;
        node *temp = p; //pä¸å¨ï¼tempè®¡ç®åç¼ä¸²
        while(temp != root && temp->count != -1)
        {
            result += temp->count;
            temp->count = -1;
            temp = temp->fail;
        }
    }
    return result;
}

int main()
{
    int ncase, num;
    scanf("%d", &ncase);
    while(ncase--)
    {
        head= tail = 0;
        root = new node();
        scanf("%d", &num);
        getchar();
        for(int i = 0; i < num; ++i)
        {
            gets(keyword);
            insert(keyword);
        }
        build_ac();
        scanf("%s", str);
        printf("%d\n", query());
    }
    return 0;
}