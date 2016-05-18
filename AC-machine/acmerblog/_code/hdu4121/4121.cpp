#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

#define pb push_back
#define cl(a) memset(a,0,sizeof(a))

using namespace std;

struct zb
{
    int x;
    int y;
};

const int fy[4]={-1,0,1,0};
const int fx[4]={0,-1,0,1};
const int hy[8]={-2,-2,-1,1,2,2,1,-1};
const int hx[8]={1,-1,-2,-2,-1,1,2,2};

vector<zb>c,h,r;
zb g;
int map[13][13];


void init()
{
    cl(map);
    c.clear();
    h.clear();
    r.clear();
}

int lie_pd(int y1,int y2,int x0,int t)
{
    int i,z;
    if (y1>y2)
    {
        int tmp=y1;
        y1=y2;
        y2=tmp;
    }
    z=0;
    for (i=y1+1;i<y2;i++)
        if (map[x0][i]) z++;
    if (z==t) return 1;
    return 0;
}

int hang_pd(int x1,int x2,int y0,int t)
{
    int i,z;
    if (x1>x2)
    {
        int tmp=x1;
        x1=x2;
        x2=tmp;
    }
    z=0;
    for (i=x1+1;i<x2;i++)
        if (map[i][y0]) z++;
    if (z==t) return 1;
    return 0;
}

int pd_general(int x0,int y0)
{
    int i;
    if (g.y==y0)
    {
        for (i=x0+1;i<g.x;i++) 
            if (map[i][y0]) return 1;
        return 0;
    }
    return 1;
}

int pd_chariot(int x0,int y0)
{
    int i,j;
    for (j=0;j<r.size();j++)
    {
        if (r[j].x==x0&&r[j].y==y0) continue;
        else if (r[j].x==x0) 
        {
            if (lie_pd(r[j].y,y0,x0,0)) return 0;
        }
        else if (r[j].y==y0)
        {
            if (hang_pd(r[j].x,x0,y0,0)) return 0;
        }
    }
    return 1;
}

int pd_connon(int x0,int y0)
{
    int i,j;
    for (j=0;j<c.size();j++)
    {
        if (c[j].x==x0) 
        {
            if (lie_pd(c[j].y,y0,x0,1)) return 0;
        }
        if (c[j].y==y0)
        {
            if (hang_pd(c[j].x,x0,y0,1)) return 0;
        }
    }
    return 1;
}

int pd_horse(int x0,int y0)
{
    int i,j,x11,y11,x1,y1;
    for (j=0;j<h.size();j++)
    {
        for (i=0;i<8;i++)
        {
            x1=h[j].x+hx[i];
            y1=h[j].y+hy[i];
            x11=h[j].x+fx[i/2];
            y11=h[j].y+fy[i/2];
            if (x1==x0&&y1==y0&&!map[x11][y11]) return 0;
        }
    }
    return 1;
}

int pd(int x0,int y0)
{
    return pd_horse(x0,y0)*pd_chariot(x0,y0)*pd_connon(x0,y0)*pd_general(x0,y0);
}

int main()
{
    int n,i,x0,y0;
    while (cin>>n)
    {   
        init();
        cin>>x0>>y0;
        if (!n&&!x0&&!y0) break;
        for (i=1;i<=n;i++)
        {
            char ch;
            zb t;
            cin>>ch;
            cin>>t.x>>t.y;
            if (ch=='G') g=t;
            if (ch=='H') h.pb(t);
            if (ch=='C') c.pb(t);
            if (ch=='R') r.pb(t);
            map[t.x][t.y]=1; 
        }
        for (i=0;i<4;i++)
        {
            int x1,y1;
            x1=x0+fx[i];
            y1=y0+fy[i];
            if ((x1>=1&&x1<=3)&&(y1>=4&&y1<=6)) 
            {
                if (pd(x1,y1))
                {
                    cout<<"NO"<<endl;
                    break;
                }
            }
        }
        if (i==4) cout<<"YES"<<endl;
    }
    return 0;
}
