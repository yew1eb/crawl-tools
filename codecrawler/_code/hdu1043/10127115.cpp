/*
Author£ºyew1eb Current Time: 2014.2.19

hdu1043 Eight
ÒòÎª×´Ì¬×ÜÊý²»¶à£¬Ö»ÓÐ²»µ½40ÍòÖÖ(9!)£¬Òò´Ë¿ÉÒÔ´ÓÄ¿±ê½Úµã¿ªÊ¼£¬
½øÐÐÒ»±é³¹µ×µÄ¹ãËÑ£¬ÕÒ³öÈ«²¿ÓÐ½â×´Ì¬µ½Ä¿±ê½ÚµãµÄÂ·¾¶¡£

×´Ì¬ÅÐÖØ£º
cantorÕ¹¿ª

×¢ÒâÓÐ¶à½â£¡£¡Special Judge
*/

#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 400000;
const int n = 9;
struct node {
    int s[9];
    int loc;
    int hf;
    string path;
} st;


int fac[9]= {1,1,2,6,24,120,720,5040,40320};

int cantor(int *a)
{
    int ans, i, j, tmp;
    ans = 0;
    for(i=0; i<n; ++i) {
        tmp = 0;
        for(j=i+1; j<n; ++j) if(a[j]<a[i]) tmp++;
        ans += fac[n-i-1]*tmp;
    }
    return ans + 1;
}

string path[MAXN];
bool vis[MAXN];

int dir[4][2]= {{-1,0},{1,0},{0,-1},{0,1}}; //u,d,l,r
char index[5]="durl";//ºÍÉÏÃæµÄÒªÏà·´£¬ÒòÎªÊÇ·´ÏòËÑË÷:±ãÓÚÊä³ö

void bfs()
{
    int i, j;
    queue<node> q;
    node cur, next;
    for(i=1; i<n; ++i) st.s[i-1] = i % n;
    st.loc = 8;
    st.path = "";
    st.hf = cantor(st.s);
    memset(vis, 0, sizeof vis );
    vis[st.hf] = 1;
    q.push(st);
    int tx, ty, dx, dy;
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        tx = cur.loc / 3;
        ty = cur.loc % 3;
        for(i=0; i<4; ++i) {
            dx = tx + dir[i][0];
            dy = ty + dir[i][1];
            if(dx<0||dx>2||dy<0||dy>2) continue;
            next = cur;
            next.loc = dx*3 + dy;
            next.s[cur.loc] = next.s[next.loc];
            next.s[next.loc] = 0;
            next.hf = cantor(next.s);
            if(!vis[next.hf]) {
                vis[next.hf] = 1;
                next.path = index[i] + next.path;
                q.push(next);
                path[next.hf] = next.path;
            }
        }
    }
}

int main()
{
    char str[100];
    int len, i, j, cnt;
    node t;
    bfs();
    while(gets(str)) {
        len = strlen(str);
        cnt = 0;
        for(i=0; i<len; ++i) {
            if(str[i]>='1' && str[i]<='8')
                t.s[cnt++] = str[i] - '0';
            else if(str[i] == 'x') {
                t.s[cnt] = 0;
                t.loc = cnt++;
            }
        }

        t.hf = cantor(t.s);
        if(vis[t.hf]) {
            printf("%s\n",path[t.hf].c_str());
        } else {
            printf("unsolvable\n");

        }
    }
    return 0;
}












