#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct room
{
    int j, f;
    bool operator < (const room t) const {
        return (double) j/f >(double)t.j /t.f;
    }
};
int main()
{
    int m, n, i;
    while(scanf("%d%d", &m, &n) && (m+1) ||(n+1))
    {
        vector<room> v;
        room r;
        double ans = 0;
        for(i=0; i<n; ++i)
        {
            scanf("%d%d",&r.j,&r.f);
            v.push_back(r);
        }
        sort(v.begin(), v.end());
        i = 0;
        while(m >0 && i<v.size())
        {

            if(v[i].f <= m)
            {
                m -= v[i].f;
                ans += v[i].j;
            }else
            {
                ans +=(double)m /v[i].f *v[i].j;
                m = 0;
            }
            ++i;
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}
