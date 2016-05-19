#include <set>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <algorithm>
#define MID(x,y) ( ( x + y ) >> 1 )
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )
#define FOR(i,s,t) for(int i=s; i<t; i++)
#define BUG puts("here!!!")
#define STOP system("pause")
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;

const int MAX = 2010;

map< string, int > m;
map< string, int >::iterator it;
struct NODE{ int to; NODE *next;};
NODE *p[MAX], node[MAX*MAX];
int num[MAX];
int cou = 0;

void init()
{
    memset(p, 0, sizeof(p));
    cou = 0;
}

void Add(int u,int v)
{
    node[cou].to = v;
    node[cou].next = p[u];
    p[u] = &node[cou++];
}

bool ans[MAX];
bool b[MAX];
string sss[MAX];
string soo[MAX];
int main()
{
    int ncases, n, q, u, v, ind = 1;
    char s1[MAX], s2[MAX];
    string ss;
    
    scanf("%d", &ncases);
    
    while( ncases-- )
    {
        m.clear();
        init();
        memset(ans, false, sizeof(ans));
        scanf("%d%d", &n, &q);
        
        int cnt = 0;
        while( n-- )
        {
            scanf("%s %s", &s1, &s2);
            ss = string(s1);
            if( m.count(ss) )    // map å¯»æ¾ï¼å¾æ¹ä¾¿å 
                u = m.find(ss)->second;
            else
            {
                u = cnt;
                sss[cnt] = ss;
                m.insert(make_pair(ss, cnt++));
            }
            ss = string(s2);
            if( m.count(ss) )
                v = m.find(ss)->second;
            else
            {
                sss[cnt] = ss;
                v = cnt;
                m.insert(make_pair(ss, cnt++));
            }            
            
            Add(u, v); Add(v, u);
        }
        
        printf("Case %d:\n", ind++);
        while( q-- )
        {
            scanf("%s", s1);
            ss = s1;
            if( !m.count(ss) ) continue; 
            int now = m.find(ss)->second;
            
            if( ans[now] == true )
            {
                printf("-\n");
                continue;
            }
            memset(b, false, sizeof(b));
            memset(num, 0, sizeof(num));
            NODE *head = p[now];
            
            while( head )
            {
                b[head->to] = true;    // now çç´æ¥èç³»äººï¼ä¹å¯ä»¥ç¨éåå­å¦ 
                head = head->next;
            }
            
            FOR(i, 0, cnt)
                if( b[i] )
                {
                    NODE *head = p[i];
                    while( head )
                    {
                        num[head->to]++;
                        head = head->next;
                    }
                }
            
            int mmax = 0;
            FOR(i, 0, cnt)
                if( num[i] > mmax && i != now && !b[i] )//æ³¨æä¸è¦èªå·±åç´æ¥èç³»äºº 
                    mmax = num[i];
            
            if( mmax == 0 )
            {
                ans[now] = true;    // ä¸æ¬¡åè¯¢é®ç´æ¥è¾åº - å³å¯ 
                printf("-\n");
                continue;
            }

            int nn = 0;
            FOR(i, 0, cnt)
                if( num[i] == mmax && !b[i] && i != now )//æ³¨æä¸è¦èªå·±åç´æ¥èç³»äºº 
                    soo[nn++] = sss[i];
            
            sort(soo, soo+nn);    // è¾åºsortãã 
            FOR(i, 0, nn)
            {
                if( i != 0 ) printf(" ");
                printf("%s",soo[i].c_str());
            }
            printf("\n");
        }
    }

return 0;
}
