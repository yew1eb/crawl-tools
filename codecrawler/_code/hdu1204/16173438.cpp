#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

const double eps=1e-12;
int main()
{
    int n,m;
    double p,q;
    while(scanf("%d%d%lf%lf",&n,&m,&p,&q)!=EOF)
    {
        double ans,r;
        if(m==0)ans=1;//å¦æm=0ï¼é£ä¹å³ä½¿n=0ä¹ä¼èµ¢
        else if(n==0||p==0||q==1)ans=0;
        else
        {
            r=q*(1-p)/(p*(1-q));//Speaklessèçæ¦çp*(1-q)
            if(fabs(r-1.0)<eps)ans=1.0*n/(n+m);//èçç¸ç­
            else ans=(1-pow(r,n))/(1-pow(r,n+m));
        }
        printf("%.2f\n",ans);
    }
    return 0;
}
/*
Markovè¿ç¨ï¼é©¬å°ç§å¤«è¿ç¨ï¼
*/
