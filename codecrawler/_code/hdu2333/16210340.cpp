#include<cstdio>
#include<string>
#include<map>
#include<cstring>
#include<iostream>
#include<algorithm>
#define MAXN 1005
#define INF 0x3f3f3f3f
using namespace std;
map< string,int > id;
int T,n,b,cnt;
char tmp[30];
struct Obj {int price,quality,type;}obj[MAXN];
bool cmp(Obj a,Obj b) {return a.quality<b.quality;}
int insert(string s)
{
    if(!id[s]) id[s]=cnt++;
    return id[s];
}
bool check(int x)
{
    int sum=0,kind=0,cheapest[MAXN];
    memset(cheapest,INF,sizeof(cheapest));//ï¿½ï¿½Â¼Ã¿ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ð¡ï¿½ï¿½Öµï¿½ï¿½ï¿½ï¿½Ê¼ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½INF
    
    for(int i=1;i<=n;++i)
    {
        if(obj[i].quality<x) continue;//ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Æ·ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ð¡ï¿½ï¿½xï¿½ï¿½ï¿½ï¿½Æ·
        if(cheapest[obj[i].type]==INF) ++kind,sum+=obj[i].price,cheapest[obj[i].type]=obj[i].price;
        else if(obj[i].price<cheapest[obj[i].type]) sum=sum-cheapest[obj[i].type]+obj[i].price,cheapest[obj[i].type]=obj[i].price;
    }
    return sum<=b && kind==cnt-1;//ï¿½ï¿½ï¿½ï¿½ï¿½Ü¼Û²ï¿½ï¿½ï¿½ï¿½ï¿½bï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ñ¡ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ò²ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½à¶¼Ñ¡ï¿½ï¿½Ò»ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ã´ï¿½ï¿½ï¿½ï¿½trueï¿½ï¿½ï¿½ï¿½ï¿½ò·µ»ï¿½false
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&b);
        cnt=1; id.clear();
        int maxquality=0;
        for(int i=1;i<=n;++i)
        {
            scanf("%s",tmp);
            obj[i].type=insert(tmp);
            scanf("%s",tmp);
            scanf("%d %d",&obj[i].price,&obj[i].quality);
            maxquality=max(maxquality,obj[i].quality);
        }
        int low=0,high=maxquality;
        while(low<high)
        {
            int mid=low+(high-low+1)/2;
            if(check(mid)) low=mid;
            else high=mid-1;
        }
        printf("%d\n",low);
    }
    return 0;
}
