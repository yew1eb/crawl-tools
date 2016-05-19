#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-4;
const double PI = acos(-1.0);
int main()
{
    //freopen("H:\\in.txt","r",stdin);
    //freopen("H:\\out.txt","w",stdout);
    double w, h, r, ans1, ans2, ans;
    while (scanf("%lf%lf", &w, &h) != EOF && w &&h)
    {
        r=min(w/2.0,h/(2.0*PI+2.0));
        ans1=PI*r*r*w;
        r=min(w/(2.0*PI),h/3.0);
        ans2=PI*r*r*(h-2.0*r);
        ans=max(ans1,ans2);
        printf("%.3lf\n",ans);
    }
    return 0;
}
