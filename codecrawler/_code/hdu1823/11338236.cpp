#include<cstdio>
#include<cstring>
#include<algorithm>

#define lson rt<<1
#define rson lson|1

using namespace std;
const int inf = 0x3f;
const int N = 200;
const int M = 1000;

double ans;

struct IntervalTree2D {
    double Max[N*4+10][M*4+10], v;
    int n, m, hleaf, Hrt, h, h1, h2, a, a1, a2;

    void query1D(int rt, int A1, int A2)
    {
        if(a1<=A1 && A2<=a2){
            ans = max(ans, Max[Hrt][rt]);
            return ;
        }
        int mid = (A1 + A2)/2;
        if(mid>=a1)
            query1D(lson, A1, mid);
        if(mid<a2)
            query1D(rson, mid+1, A2);
    }

    void query2D(int rt, int H1, int H2)
    {
        if(h1<=H1 && H2<=h2)
        {
            Hrt = rt;
            query1D(1, 0, m);
            return ;
        }
        int mid = (H1 + H2)/2;
        if(mid>=h1)
            query2D(lson, H1, mid);
        if(mid<h2)
            query2D(rson, mid+1, H2);
    }

    void modify1D(int rt, int A1, int A2)
    {
        if(A1==A2){
            if(hleaf==1)
            {
                Max[Hrt][rt] = max(v, Max[Hrt][rt]);
                return ;
            }
            Max[Hrt][rt] = max(Max[Hrt<<1][rt], Max[Hrt<<1|1][rt]);
            return ;
        }
        int mid = (A1 + A2)/2;
        if(mid>= a)
            modify1D(lson, A1, mid);
        else
            modify1D(rson, mid+1, A2);
        Max[Hrt][rt] = max(Max[Hrt][lson], Max[Hrt][rson]);
    }

    void modify2D(int rt, int H1, int H2)
    {
        if(H1 == H2)
        {
            Hrt = rt;
            hleaf = 1;
            modify1D(1, 0, m);
            return ;
        }
        int mid = (H1+H2)/2;
        if(mid>=h)
            modify2D(lson, H1, mid);
        else
            modify2D(rson, mid+1, H2);
        Hrt = rt;
        hleaf = 0;
        modify1D(1, 0, m);
    }

    void query()
    {
        ans = -inf;
        query2D(1, 100, n);
    }

    void modify()
    {
        modify2D(1, 100, n);
    }

    void clear()
    {
        for(int i=0; i<N*4+5; ++i)
            for(int j=0; j<1000*4+5; ++j)
                Max[i][j] = -inf;
    }
};

IntervalTree2D t;


int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        t.clear();
        t.n = 200;
        t.m = 1000;
        while(n--){
            char ch;
            scanf(" %c", &ch);
            int h, hh;
            double a, aa;
            if(ch=='I'){
                scanf("%d%lf%lf", &h, &a, &aa);
                t.h = h;
                t.a = int(a*10);
                t.v = aa;
                t.modify();
            }else
            {
                scanf("%d%d%lf%lf", &h, &hh, &a, &aa);
                if(h>hh) swap(h, hh);
                if(a>aa) swap(a, aa);
                t.h1 = h;
                t.h2 = hh;
                t.a1 = int(a*10);
                t.a2 = int(aa*10);
                t.query();
                if(ans < 0)
                    printf("-1\n");
                else
                    printf("%.1f\n", ans);
            }
        }
    }
    return 0;
}
