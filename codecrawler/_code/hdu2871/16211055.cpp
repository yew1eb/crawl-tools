#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 50000 + 10;
struct SegTree
{
    int left, right;
    int maxval, lval, rval;
    int cover;
    int mid()
    {
        return (left + right) / 2;
    }
    int dis()
    {
        return right - left + 1;
    }
    void init()
    {
        maxval = lval = rval = cover ? 0 : dis();
    }
}st[N*4];

struct block
{
    int begin, end;
};
vector<block> v;

bool cmp(const block &a, const block &b)
{
    return a.begin < b.begin;
}

void build(int left, int right, int root)
{
    st[root].left = left;
    st[root].right = right;
    st[root].cover = 0;
    st[root].init();
    if (left == right)
        return;
    int mid = st[root].mid();
    build(left, mid, root*2);
    build(mid+1, right, root*2+1);
}

void update(int left, int right, int cov, int root)
{
    if (left <= st[root].left && st[root].right <= right)
    {
        st[root].cover = cov;
        st[root].init();
        return;
    }
    if (st[root].cover != -1)
    {
        st[root*2].cover = st[root*2+1].cover = st[root].cover;
        st[root*2].init();
        st[root*2+1].init();
        st[root].cover = -1;
    }
    int mid = st[root].mid();
    if (left <= mid)
        update(left, right, cov, root*2);
    if (right > mid)
        update(left, right, cov, root*2+1);

    st[root].maxval = max(st[root*2].rval + st[root*2+1].lval, max(st[root*2].maxval, st[root*2+1].maxval));
    st[root].lval = st[root*2].lval;
    st[root].rval = st[root*2+1].rval;
    if (st[root*2].lval == st[root*2].dis())
        st[root].lval += st[root*2+1].lval;
    if (st[root*2+1].rval == st[root*2+1].dis())
        st[root].rval += st[root*2].rval;
}

int query(int d, int root)
{
    if (st[root].maxval < d)
        return 0;
    if (st[root].left == st[root].right)
        return st[root].left;
    if (st[root].cover != -1)
    {
        st[root*2].cover = st[root*2+1].cover = st[root].cover;
        st[root*2].init();
        st[root*2+1].init();
        st[root].cover = -1;
    }
    if (st[root*2].maxval >= d)
        return query(d, root*2);
    else if (st[root*2].rval + st[root*2+1].lval >= d)
        return st[root*2].right - st[root*2].rval + 1;
    else return query(d, root*2+1);
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        build(1, n, 1);
        v.clear();

        int x;
        char s[6], ch;
        while (m--)
        {
            scanf("%c", &ch);  //read '\n' in the end of last line
            scanf("%s", s);
            if (s[0] == 'R')
            {
//              build(1, n, 1);    //TLE!!!
                update(1, n, 0, 1);
                v.clear();
                printf("Reset Now\n");
            }
            else if (s[0] == 'N')
            {
                scanf("%d", &x);
                int a = query(x, 1);
                if (a == 0)
                    printf("Reject New\n");
                else
                {
                    printf("New at %d\n", a);
                    update(a, a + x - 1, 1, 1);

                    //update v[]
                    block y;
                    y.begin = a, y.end = a + x - 1;
                    vector<block>::iterator it;
                    it = upper_bound(v.begin(), v.end(), y, cmp); //lower_bound() is all right.
                    v.insert(it, y);
//                  v.push_back(y);           //TLE!!!
//                  sort(v.begin(), v.end(), cmp);
                }
            }
            else if (s[0] == 'F')
            {
                scanf("%d", &x);
                //find which block the x located
                block y;
                y.begin = x, y.end = x;
                vector<block>::iterator it;
                it = upper_bound(v.begin(), v.end(), y, cmp);  //lower_bound() may make the code uglier.

                int tmp = it - v.begin() - 1;
                if (tmp == - 1 || v[tmp].end < x)
                    printf("Reject Free\n");
                else
                {
                    printf("Free from %d to %d\n", v[tmp].begin, v[tmp].end);
                    update(v[tmp].begin, v[tmp].end, 0, 1);
                    v.erase(v.begin() + tmp);
                }
            }
            else
            {
                scanf("%d", &x);
                if (x > v.size())
                    printf("Reject Get\n");
                else printf("Get at %d\n", v[x-1].begin);
            }
        }
        printf("\n");
    }
    return 0;
}