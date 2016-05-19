#include <iostream>
#include <algorithm>
using namespace std;
int n,p[105]; 
struct bian
{
    int x,y,d;
     
}e[5105];//waäºnæ¬¡ï¼å±ç¶æ¯æ°ç»å¼å°äºï¼æäº¤æ¶ä¸æç¤ºè¿è¡éè¯¯ï¼ç´æ¥wa,æ è¯­â¦â¦

int cmp(bian a1,bian b1)
{
    return a1.d<b1.d;
}
void init()
{
    for(int i=1;i<=n;i++)
     p[i]=i;
}
int find(int x)
{
    if(x==p[x]) return x;
    else return p[x]=find(p[x]);
}

void jie(int x,int y)
{
    int ta=find(x),tb=find(y);
    if(ta!=tb) p[ta]=tb;
}


int clus(int k)
{
    int x,y,i,c, ans;
    init();
    for(ans=c=i=0;i<k;i++)
    {
        x=e[i].x;y=e[i].y;
        if(find(x)!=find(y))
        {
            ans+=e[i].d; c++;
            jie(x,y);
        }
        if(c==n-1) return ans;
    }
}

int main()
{
    int i,j,k,t,d1,m;
    while(cin>>n&&n)
    {   if(n==1) cout<<0<<endl;//çº ç»äºä¸ä¸åï¼å±ç¶æ²¡èèç­äº1çæåµï¼è¦æ³¨æç»èå 
        else
        {for(k=i=0;i<n*(n-1)/2;i++,k++)
            scanf("%d%d%d",&e[k].x,&e[k].y,&e[k].d);
    sort(e,e+k,cmp);
    cout<<clus(k)<<endl;
        }
    }
    return 0;
}