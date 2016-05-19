#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#define LL long long
#define mod 1000000007
using namespace std;

struct TROOP{
LL x,y,num;
TROOP(){}
TROOP(LL nx,LL ny,LL nnum){x=nx,y=ny,num=nnum;}
}troop[200005];

map<LL,set<LL> >MX;
map<LL,set<LL> >MY;
set<LL>::iterator it;

LL node[200005];

LL findroot(LL x)
{
    if(node[x]!=x) node[x]=findroot(node[x]);

    return node[x];
}

int main()
{
    LL m,x,y,n,i,t,cnt,root,a,b,ans;
    char s[5];

    while(~scanf("%I64d%I64d",&n,&m))
    {
        MX.clear();
        MY.clear();

        for(i=1;i<=n;i++)
        {
            scanf("%I64d%I64d",&x,&y);

            troop[i].x=x;
            troop[i].y=y;
            troop[i].num=1;

            node[i]=i;

            MX[x].insert(i);
            MY[y].insert(i);
        }

        cnt=n+1;

        ans=0;

        scanf("%I64d",&t);

        while(t--)
        {
            scanf("%s",s);

            if(s[0]=='Q')
            {
                scanf("%I64d",&a);

                a^=ans;

                root=findroot(a);//æ¾å°aæå¨çéå

                x=troop[root].x;
                y=troop[root].y;

                LL num=0;

                ans=0;

                for(it=MX[x].begin();it!=MX[x].end();it++)
                {
                    num+=troop[*it].num;

                    LL temp=abs(troop[*it].y-y);

                    temp%=mod;

                    ans=(temp*temp%mod*troop[*it].num%mod+ans)%mod;

                    node[*it]=cnt;//æåcntï¼cntæ¯æ§è¡Qæä½ä¹åæ°çæ ¹ï¼ç¨æ¥æ è®°æ°çéå

                    MY[troop[*it].y].erase(*it);//*itå·²ç»è®¡ç®è¿ï¼ä»MY[]éåéå æï¼é¿åéå¤è®¡ç®
                }

                for(it=MY[y].begin();it!=MY[y].end();it++)
                {
                    num+=troop[*it].num;

                    LL temp=abs(troop[*it].x-x);

                    temp%=mod;

                    ans=(temp*temp%mod*troop[*it].num%mod+ans)%mod;

                    node[*it]=cnt;//åç

                    MX[troop[*it].x].erase(*it);//åç
                }

                node[cnt]=cnt;//æåèªå·±ï¼å«å¿äº
                troop[cnt]=TROOP(x,y,num);//æ§è¡Qæä½ä¹åå½¢æçæ°éå
                MX[x].clear();
                MY[y].clear();
                MX[x].insert(cnt);//å¨ç®æ éåä¸­æå¥
                MY[y].insert(cnt);

                cnt++;

                printf("%I64d\n",ans);
            }
            else
            {
                scanf("%I64d%I64d",&a,&b);

                a^=ans;

                root=findroot(a);//æ¾å°aæå¨çéåï¼å³açæ ¹èç¹

                x=troop[root].x;
                y=troop[root].y;

                troop[root].num--;//éåéçè®¡æ°åä¸

                if(!troop[root].num)//å¦æéåçè®¡æ°ä¸º0åæè¯¥éåå æ
                {
                    MX[x].erase(root);
                    MY[y].erase(root);
                }

                if(s[0]=='U')
                {
                    troop[a]=TROOP(x-b,y,1);

                    node[a]=a;//aæåèªå·±ï¼ä½ä¸ºæ°çæ ¹

                    MX[x-b].insert(a);//å¨ç®æ ä½ç½®æå¥
                    MY[y].insert(a);
                }
                else if(s[0]=='L')//ä»¥ä¸åç
                {
                    troop[a]=TROOP(x,y-b,1);

                    node[a]=a;

                    MX[x].insert(a);
                    MY[y-b].insert(a);
                }
                else if(s[0]=='D')
                {
                    troop[a]=TROOP(x+b,y,1);

                    node[a]=a;

                    MX[x+b].insert(a);
                    MY[y].insert(a);
                }
                else if(s[0]=='R')
                {
                    troop[a]=TROOP(x,y+b,1);

                    node[a]=a;

                    MX[x].insert(a);
                    MY[y+b].insert(a);
                }
            }
        }
    }
}
