#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
struct node
{
    int p,h;
}d[1002];
bool cmp(node a,node b)
{
    if(a.p==b.p)
        return a.h>b.h;
    return a.p<b.p;
}
int main()
{
    //fstream cin("d:\\test.txt");
    int c,n,m,i,money;
    double sum;
    while(!cin.eof() && cin>>c)
    {
        while(c--)
        {
            cin>>n>>m;
            for(i=0;i<m;++i)
                cin>>d[i].p>>d[i].h;
            sort(d,d+m,cmp);
            sum=0;
            money=0;
            for(i=0;i<m;++i)
            {
                money+=d[i].p*d[i].h;
                sum+=d[i].h;
                if(money>n)
                {
                    sum-=(money-n)*1.0/d[i].p;
                    break;
                }
            }
            printf("%.2lf\n",sum);
        }
    }
    return 0;
}
