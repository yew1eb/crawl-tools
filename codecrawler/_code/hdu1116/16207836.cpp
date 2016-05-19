#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
#define MAXN 30
int pre[MAXN], in[MAXN], out[MAXN];
bool visit[MAXN];

int find(int x)
{
    return x == pre[x] ? x : find(pre[x]);
}

void join(int x, int y)
{
    int root1, root2;
    root1 = find(x);
    root2 = find(y);
    if(root1 != root2)
        pre[root2] = root1;
}

int main()
{
    int ncase;
    int wordnum, len; //åè¯ä¸ªæ°ï¼æ¯ä¸ªåè¯é¿åº¦
    int start, end; //è½¬åä¸ºè¾¹
    char str[1010];
    int innum, outnum; //è®°å½å¥åº¦åºåº¦ä¸ç¸ç­é¡¶ç¹ä¸ªæ°
    int root; //æ ¹ç»ç¹ä¸ªæ°
    bool flag; //å¤æ­è¿éæ§
    bool flag1; //å¤æ­å¥åº¦ååºåº¦æ¯å¦æ¯1æè0
    scanf("%d", &ncase);
    while(ncase--)
    {
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        memset(visit, false, sizeof(visit));
        for(int i = 1; i < MAXN; ++i)
            pre[i] = i;
        innum = outnum = root = 0;
        flag = flag1 = true;
        scanf("%d", &wordnum);
        for(int i = 1; i <= wordnum; ++i)
        {
            scanf("%s", str);
            len = strlen(str);
            start = str[0] - 'a' + 1;
            end = str[len - 1] - 'a' + 1;
            visit[start] = true;
            visit[end] = true;
            out[start]++;
            in[end]++;
            join(start, end);
        }
        for(int i = 1; i < MAXN; ++i)
        {        
            if(visit[i])
            {
                if(pre[i] == i)
                    root++;
                if(in[i] != out[i])
                {
                    if(in[i] - out[i] == 1)
                        innum++;
                    else if(out[i] - in[i] == 1)
                        outnum++;
                    else 
                        flag1 = false;
                }
            }
            if(root > 1)
            {
                flag = false;
                break;
            }
        }
        if((flag && innum == 0 && outnum == 0 && flag1) || (flag && innum == 1 && outnum == 1 && flag1))
            printf("Ordering is possible.\n");
        else
            printf("The door cannot be opened.\n");
    }
    return 0;
}