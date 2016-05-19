/*
 What a TROUBLESOME Problem!!!


 Obviously, we should construct a sparse table which has
 60 * 63 rows and 60 + 12 colums.
     60 * 63 rows
         60 means we can place the "center" of a block on a specific grid.
         Besides, as block can be rotated or fliped,
        we can regard the transformed-block as a distinct block.
        So we get 63 distinct blocks.
        The classification above can avoid most of duplicate answers.
         (About the "center": Imagine that
        each block's original form can be place in a 3 * 5 matrix,
        then intuitively, (2, 2) will be the center lol)
    60 + 12 colums
         60 colums indicate 60 grids
        12 colums indicate that each block can be used at most one time.


 Then dance!!!


 As 60 only has 6 factor thus I can work out all the answers in advance
 and I must do, otherwise, I would get a TLE by using my DLX.
 At last, all the answers should be divided by 4,
 because it includes some duplicate results
 which is a rotating or flipping of another results.


 HINTS about rotating & flipping:
     If a block is axisymmetry or centrosymmetry, it can only generate 3 more blocks.
    If a block is axisymmetry and centrosymmetry, originnal form is the only state.


    Why?


    Generally, we can get all 7 generated blocks in total
    by rotate the original block 3 times clockwisely and
    flip it, then rotate it 3 times clockwisely.
    As a axisymmetry block's flipping-rotating-status are included in rotating-status,
        and centrosymmery block can return to originnal form by rotate 180 degree,
    the block which has one of these characteristics
    can only generate 3 more distinct blocks.


 Last but not least, clear your mind and thanks to read my suck english-expression.
 */
#if 1 //Header
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
#endif
#if 1 //Macro
//STL-Alias
#define UN(c, a) unique(c, a)
#define MS(c, a) memset(c, a, sizeof c)
#define FLC(c, a ,b) fill(c, c + a, b)
#define LOS(c, a, b) lower_bound(c, a, b)
#define UPS(c, a, b) upper_bound(c, a, b)
//Syntax-Alias
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
//DEBUG
#define FK puts("Fu*k here!")
#define PA(s, c, a, b, p, f){\
    printf(s);\
    Rep(c, a, b) printf(p, (f));\
    puts("");}
//Constant
#define INFI (0x7fffffff)
#define MOD ()
#define MAXN (66)
#define MAXT (12)
//Type-Alias
typedef long long LL;
typedef long double LD;
typedef int AI[MAXN];
typedef bool AB[MAXN];
typedef double AD[MAXN];
typedef LL ALL[MAXN];
typedef LD ALD[MAXN];
#endif


//DLX
struct DLX
{
#define DLXR (MAXN * MAXT * 8)
#define DLXC (MAXT + MAXN)
#define DF(c, a, b) for (int c = a[b]; c != b; c = a[c])
    typedef int DS[DLXR * DLXC], DR[DLXR], DC[DLXC];
    DS L, R, U, D, O, C;
    DR P;
    DC S;
    vector<vector<int> > ans;
    int id, cr, rh, ms, res;
    void ini(int n)
    {
        id = ++n;
        Rep(i, 0, n)
        {
            L[i] = (i - 1 + n) % n;
            R[i] = (i + 1) % n;
            U[i] = D[i] = i;
        }
        MS(S, cr = 0);
        MS(P, 0);
        ms = INFI;
        res = 0;
        ans.clear();
    }    
    void ins(int i, int j)
    {
        i++; j++;
        if (cr < i)
        {
            rh = L[id] = R[id] = id;
            cr = i;
        }
        L[id] = L[rh]; R[id] = rh;
        R[L[rh]] = id; L[rh] = id;
        U[id] = U[j]; D[id] = j;
        D[U[j]] = id; U[j] = id;
        S[j]++; O[id] = i; C[id++] = j;
    }
    void erm(int c)
    {
        L[R[c]] = L[c]; R[L[c]] = R[c];
        DF(i, D, c) DF(j, R, i)
            U[D[j]] = U[j], D[U[j]] = D[j], S[C[j]]--;
    }
    void ers(int c)
    {
        L[R[c]] = c; R[L[c]] = c;
        DF(i, D, c) DF(j, R, i)
            U[D[j]] = j, D[U[j]] = j, S[C[j]]++;
    }
    bool edf(int sp)
    {
        if (!R[0] || R[0] >= ms)
        {
            res++;
            return 1;
        }
        int x = R[0];
        DF(i, R, 0)
            if (i < ms && S[i] < S[x]) x = i;
        erm(x);
        DF(i, D, x)
        {
            DF(j, R, i) erm(C[j]);
            edf(sp + 1);
            DF(j, L, i) ers(C[j]); //L
        }
        ers(x);
        return 0;
    }
} dlx;


#if 1 //Tiles
#if 1 //Direction
#define O  (0 )
#define E  (1 )
#define S  (2 )
#define W  (3 )
#define N  (4 )
#define SE (5 )
#define SW (6 )
#define NW (7 )
#define NE (8 )
#define EE (9 )
#define WW (10)
//   NW  N  NE
//WW  W  O   E EE
//   SW  S  SE
#endif
int dir[11][2] = {
    {0, 0},//O
    {0, 1}, {1,  0}, { 0, -1}, {-1, 0},//E ,  S,  W,  N 
    {1, 1}, {1, -1}, {-1, -1}, {-1, 1},//SE, SW, NW, NE
    {0, 2}, {0, -2}//EE, WW 
};
int til[MAXT][5] = {
    {SE,  S, SW,  W,  NW},//1
    { O,  E, EE,  W,  WW},//2
    { O,  E,  S,  W,   N},//3
    { E, SE,  S, SW,   W},//4
    { O,  E, EE,  W,  NW},//5
    { O, SE,  S,  W,  NW},//6
    { O,  E, EE,  W,   N},//7
    { O,  E, SW,  W,  NE},//8
    { O,  E,  S, SW,   N},//9
    { O, SE,  S, SW,   N},//10
    { O,  E, SE,  S,  SW},//11
    { O,  E, EE,  S,  SW},//12
};
int otm[MAXT + 1] = {4, 2, 1, 4, 8, 4, 8, 8, 8, 4, 8, 8, 67}; //otm[i] = (Flip or not) * 4 + Rotate-times.
int sot[MAXT] = {0, 4, 6, 7, 11, 19, 23, 31, 39, 47, 51, 59}; //sum of otm[i] which i in [0, i - 1].
void flp(int &x, int &y, int f) //Flipping
{
    if (f) x = -x;
}
void rot(int &x, int &y, int b) //Rotation
{
    while (b--)
    {
        swap(x, y);
        y = -y;
    }
}
#endif


int n, m;


vector<int> P;
bool CAI(int x, int y, int t, int f, int b) //Check and Insert
{
    P.clear();
    Rep(i, 0, 5)
    {
        int p = dir[til[t][i]][0],
            q = dir[til[t][i]][1];
        flp(p, q, f);
        rot(p, q, b);
        int tx = x + p, ty = y + q;
        if (tx < 0 || n <= tx || ty < 0 || m <= ty)
            return 0;
        else P.push_back(tx * m + ty);
    }
    int u = (x * m + y) * otm[MAXT] + sot[t] + f * 4 + b;
    dlx.ins(u, t + n * m);
    Rep(i, 0, P.size()) dlx.ins(u, P[i]);
    return 1;
}


map<int, int> ans;
void PTM() //Pretreatment
{
    ans[3] = 8;
    ans[4] = 1472;
    ans[5] = 4040;
    ans[6] = 9356;
}
void PPT() //Pre-Pretreatment
{
    Rep(i, 1, 31) if (i * i <= 60)
    {
        n = i;
        m = 60 / n;
        dlx.ini(MAXT + n * m);
        dlx.ms = n * m;
        Rep(pos, 0, n * m) Rep(t, 0, MAXT)
            Rep(i, 0, otm[t]) 
            {
                if (t == 7 && i % 4 > 1) continue; //Because block 7 is centrosymmetry
                CAI(pos / m, pos % m, t, i / 4, i % 4);
            }
        dlx.edf(0);
        printf("%4d = %d\n", i, dlx.res);
    }
}


int main()
{
    //PPT();
    PTM();
    while (~scanf("%d%d", &n, &m))
    {
        //Initialize
        //Solve
        printf("%d\n", ans[min(n, m)] / 4);
    }
    return 0;
}



   
