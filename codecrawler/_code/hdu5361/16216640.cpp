/*è¸å®ï¼ï¼åªåï¼ï¼*/
/*
   å¨åºé´ä¹ä¸çæç­è·¯ï¼ï¼ï¼
   åå¼å§åçæ¶åï¼æ³å°æ´åè¯å®ä¼å·®è¶æ¶ï¼æ²¡æ³å°ç¨set
   
   æè·¯ï¼å©ç¨setå¯¹åºé´åææçcostå¼è¿è¡æåºä¹åï¼åæ¶å©ç¨set
   å¯é¤å»åºé´åå·²ç»å­å¨çæç­è·¯ï¼è¿æ ·æå¤§çç¼©å°äºæ¶é´ï¼æ´åä¹æ¯
   éè¦å¥½çå®¹å¨æ´å å¿«æ·
*/
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#include<stack>
using namespace std;
#define ll long long
#define N 200005
int lp[N],rp[N],n,data[N];
ll dis[N];
struct Node{
    int id;
    ll cost;
};
set<Node>findd;
set<int>num;
bool operator < (Node a,Node b)
{
    if(a.cost==b.cost) return a.id<b.id;
    return a.cost<b.cost;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&lp[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&rp[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&data[i]);
        findd.clear();
        num.clear();
        memset(dis,-1,sizeof(dis));

        Node x,y;
        x.id=1;
        x.cost=data[1];
        findd.insert(x);
        dis[1]=0;
        for(int i=2;i<=n;i++)
            num.insert(i);

        set<int>::iterator it,it2;
        while(findd.size()>0){
            x=*findd.begin();
            findd.erase(findd.begin());

            //ä»*it.idçå·¦ä¾§å¼å§æ¥æ¾
            it=num.lower_bound(x.id-rp[x.id]);
            while(it!=num.end()&&*it<=x.id-lp[x.id]){
                y.id=*it;
                y.cost=x.cost+data[y.id];
                findd.insert(y);
                dis[y.id]=x.cost;
                it2=it++;
                num.erase(it2);
            }
            //ä»*it.idçå³ä¾§å¼å§æ¥æ¾
            it=num.lower_bound(x.id+lp[x.id]);
            while(it!=num.end()&&*it<=x.id+rp[x.id]){
                y.id=*it;
                y.cost=x.cost+data[y.id];
                findd.insert(y);
                dis[y.id]=x.cost;
                it2=it++;
                num.erase(it2);
            }
        }
        printf("%d",dis[1]);
        for(int i=2;i<=n;i++)
            printf(" %lld",dis[i]);
        printf("\n");
    }
    return 0;
}
