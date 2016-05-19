#include <iostream>
#include <cmath>
using namespace std;

const double pi=acos(-1.0);
const int N=105;
struct point{ double x,y,z; }; 
double dist(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)
        +(a.z-b.z)*(a.z-b.z));
}
int main()
{
    int n,m;
    point p[N];
    while(cin>>n>>m&&(n||m))
    {
        int i,j;
        point o;o.x=0;o.y=0,o.z=0;
        double r=40000.0/(2*pi);
        int ans=0;
        for(i=0;i<n;i++)        
            cin>>p[i].x>>p[i].y>>p[i].z;
        for(i=0;i<m;i++)
        {
            point tg;
            cin>>tg.x>>tg.y>>tg.z;
            bool flag=0;
            for(j=0;j<n;j++)
            {    
                double dt=dist(p[j],o);
                double dtj=dist(p[j],tg);
                if(sqrt(dt*dt-r*r)>=dtj)
                { flag=1; break;}
            }
            if(flag)ans++;
        }
        cout<<ans<<endl;
    }
}
