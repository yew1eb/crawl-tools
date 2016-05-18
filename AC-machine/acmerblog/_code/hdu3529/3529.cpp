#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector> 
using namespace std;
const int inf = (-1u>>1);
#define N 15*15 
#define M N
struct node{
	int r,c;
	node *L,*R,*U,*D;
};
node DD[N*4+5], row[N + 5], col[M+5], head;
int cnt, size[M+5];
int n, m;
char s[20][20]; 
int tag[20][20]; 
int ans; 
int rcnt, ccnt; 

inline void init(int r, int c){
 cnt = 0;
 head.L = head.R = head.U = head.D = &head;
 for (int i = c - 1; i >= 0; i--){
 col[i].c = i;
 col[i].r = r;
 col[i].L = &head;
 col[i].R = head.R;
 col[i].L->R = col[i].R->L = &col[i];
 col[i].U = col[i].D = &col[i];
 size[i] = 0; 
 } 
 for (int i = r - 1; i >= 0; i--){
 row[i].r = i;
 row[i].c = c;
 row[i].U = &head;
 row[i].D = head.D;
 row[i].U->D = row[i].D->U = &row[i];
 row[i].L = row[i].R = &row[i]; 
 }
}

inline void delLR(node *p){
 p->L->R = p->R;
 p->R->L = p->L;
}
inline void delUD(node *p){
 p->U->D = p->D;
 p->D->U = p->U;
} 
inline void recLR(node *p){
 p->L->R = p->R->L = p;
}
inline void recUD(node *p){
 p->U->D = p->D->U = p;
} 
inline void add(int r, int c){
 node *p = &DD[cnt++];
 p->c = c;
 p->r = r;
 p->U = &col[c];
 p->D = col[c].D;
 p->U->D = p->D->U = p;
 p->L = &row[r];
 p->R = row[r].R;
 p->L->R = p->R->L = p;
 size[c]++;
} 

 


void cover(node *p){
 if (p->c == ccnt)
 return;
 node *q;
 for (q = p->D; q != p; q = q->D){
 delLR(q); 
 }
} 

void resume(node *p){
 if (p->c == ccnt)
 return;
 node *q;
 for (q = p->D; q != p; q = q->D){
 recLR(q); 
 }
}

int h(){
 bool vis[N] = {false};
 node *p, *q, *pi;
 int nu = 0; 
 for (p = head.R; p != &head; p = p->R){
 if (!vis[p->c]){
 vis[p->c] = true;
 nu++;
 for (q = col[p->c].D; q != &col[p->c]; q = q->D)
 for (pi = q->R; pi != q; pi = pi->R)
 vis[pi->c] = true;
 }
 } 
 return nu;
} 
 
void DLX(int k){
 node *p;
 if (head.L == (&head)){
 ans = k; 
 return;
 }
 if (k + h() >= ans)return; 
 
 int MIN = inf, c = 1;
 for (p = head.R; p != (&head); p = p->R){
 if (size[p->c] < MIN){
 MIN = size[p->c];
 c = p->c;
 }
 }
 
 for (p = col[c].D; p != (&col[c]); p = p->D){
 node *q;
 cover(p); 
 for (q = p->L; q != p; q = q->L){
 cover(q);
 }
 DLX(k + 1); 
 for (q = p->R; q != p; q = q->R){ 
 resume(q);
 } 
 resume(p); 
 }
}


 
int main(){
 //freopen("in.txt", "r", stdin);
 // freopen("out.txt", "w", stdout); 
 while (scanf("%d %d", &n, &m) == 2){
 rcnt = 0, ccnt = 0;
 for (int i = 0; i < n; i++){
 scanf("%s", s[i]);
 for (int j = 1; s[i][j]; j++){
 if (s[i][j] == '#')
 tag[i][j] = ccnt++;
 } 
 }
 init((n - 2 )*(m - 2), ccnt); 
 for (int i = 1; i < n - 1; i++){
 for (int j = 1; j < m - 1; j++){
 int x, y; 
 if (s[i][j] == '.'){
 x = i, y = j - 1;
 while (s[x][y] == '.')y--;
 if (s[x][y] == '#')add(rcnt, tag[x][y]);
 
 x = i - 1, y = j;
 while (s[x][y] == '.')x--;
 if (s[x][y] == '#')add(rcnt, tag[x][y]);
 
 x = i, y = j + 1;
 while (s[x][y] == '.')y++;
 if (s[x][y] == '#')add(rcnt, tag[x][y]); 
 
 x = i + 1, y = j;
 while (s[x][y] == '.')x++;
 if (s[x][y] == '#')add(rcnt, tag[x][y]);
 
 rcnt++; 
 } 
 }
 }
 ans = inf;
 DLX(0);
 printf("%d\n", ans); 
 }
 return 0;
}