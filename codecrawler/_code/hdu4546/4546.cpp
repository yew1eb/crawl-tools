/** head files*/
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

/** some operate*/
#define PB push_back
#define MP make_pair
#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
#define MSET(arr,val) memset(arr,val,sizeof(arr))
#define MAX3(a,b,c) max(a,max(b,c))
#define MAX4(a,b,c,d) max(max(a,b),max(c,d))
#define MIN3(a,b,c) min(a,min(b,c))
#define MIN4(a,b,c,d) min(min(a,b),min(c,d))

/** some const*/
#define N 222222
#define M 222222
#define PI acos(-1.0)
#define oo 1111111111

/** some alias*/
typedef long long ll;



/** some template names, just push ctrl+j to get it in*/
//manacher
int a[N];
typedef struct data
{
	int start,i;
	data():start(0),i(0){}
	data(int a, int b):start(a),i(b){}
}way;
struct cmp
{
    bool operator()(const data &x, const data &y)
	{
	    return x.start+a[x.i]>y.start+a[y.i];
	}
};
priority_queue< way, vector<way> , cmp > pq;
int main()
{
    int i,n,m,t,ans,cs=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;++i)
            scanf("%d",&a[i]);
        sort(a,a+n);
        while(!pq.empty())pq.pop();
        pq.push(data(0,0));
        ans=0;
        while(m--)
        {
            if(pq.empty())continue;
            way tmp=pq.top();
            ans=tmp.start+a[tmp.i++];
            pq.pop();
            if(tmp.i<n)
            {
                pq.push(tmp);
                tmp.start=ans;
                pq.push(tmp);
            }
        }
        printf("Case #%d: %d\n",++cs,ans);
    }
	return 0;
}
