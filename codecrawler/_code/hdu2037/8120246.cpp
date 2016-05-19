#include <cstdio>
#include <algorithm>
using namespace std;
struct program {
    int start;
    int end;
/*
    bool operator <(const program t) const{
        if(this->start !=t.start)
            return this->start < t.start;
       else
            return this->end < t.end;
    }
*/
};
/*
bool operator <(const program &a, const program &b)
{
    if(a.start !=b.start)
        return a.start <b.start;
    else
        return a.end <b.end;
}
*/
int cmp(const program &a, const program &b)
{
    if(a.start !=b.start)
        return a.start <b.start;
    else
        return a.end <b.end;
}
const int N = 101;
program list[N];

int main()
{
    int n, i, total, mark;
    //freopen("in.txt","r",stdin);
    while(scanf("%d",&n),n)
    {
        for(i=0;i<n;i++)
            scanf("%d%d",&list[i].start, &list[i].end);
        sort(list,list+n,cmp);
        //for(i=0;i<n;i++) printf("%d %d\n", list[i].start, list[i].end);
        total = 1; mark = list[0].end;
        for(i=1;i<n;i++)
            if(mark <=list[i].start)
            {
                mark = list[i].end;
                total++;
            }else
            {
                if(mark >list[i].end)
                    mark = list[i].end;
            }
        printf("%d\n",total);
    }
    return 0;
}
