#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 10010

struct node
{
    int parent; //æ ¹èç¹
    int son; //å­èç¹
    int transport; //è½¬ç§»æ¬¡æ°
}p[N];

int find(int x)
{
    int temp;
    if(x == p[x].parent)
        return x;
    else
    {
        temp = p[x].parent;
        p[x].parent = find(p[x].parent);
        p[x].transport += p[temp].transport; //è¿ç¹éè¦åå¤æ£æ©
    }
    return p[x].parent;
}

void join(int x, int y)
{
    int root1, root2;
    root1 = find(x);
    root2 = find(y);
    if(root1 == root2)
        return ;
    p[root1].parent = root2;
    p[root1].transport++; //æ ¹èç¹è½¬ç§»æ¬¡æ°+1ï¼è¦çè§£
    p[root2].son += p[root1].son;
    p[root1].son = 0;
}

int main()
{
    int ncase, T = 1;
    int num, querynum;
    char ope;
    int from, to;
    int querycity;
    int ans;
    scanf("%d", &ncase);
    while(ncase--)
    {
        scanf("%d%d", &num, &querynum);
        for(int i = 1; i <= num; ++i) //åå§å
        {
            p[i].parent = i;
            p[i].son = 1;
            p[i].transport = 0;
        }
        printf("Case %d:\n", T++);
        for(int i = 0; i < querynum; ++i)
        {
            scanf("%*c%c", &ope);
            if(ope == 'T')
            {
                scanf("%d%d", &from, &to);
                join(from, to);
            }
            else
            {
                scanf("%d", &querycity);
                ans = find(querycity);
                printf("%d %d %d\n", ans, p[ans].son, p[querycity].transport); //çº ç»äº3ä¸ªå°æ¶~~
            }
        }
    }
    return 0;
}        