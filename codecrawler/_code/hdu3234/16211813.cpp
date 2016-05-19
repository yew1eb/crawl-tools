/*
    è½¬èªï¼http://www.cppblog.com/Yuan/archive/2010/09/02/125667.html?opt=adminç¨è®¸æ¹å
    æn(n<=20000)ä¸ªæªç¥çæ´æ°X0,X1,X2Xn-1ï¼æä»¥ä¸Qä¸ª(Q<=40000)æä½ï¼ 
    I p v :åè¯ä½ Xp=v 
    I p q v :åè¯ä½ Xp Xor Xq=v 
    Q k p1 p2 â¦ pk : è¯¢é® Xp1 Xor Xp2 .. Xor Xpkï¼ kä¸å¤§äº15ã 
    å¦æå½åçIè·ä¹åçæå²çªçè¯ï¼è·³åº    

    å¹¶æ¥éæ©å±ï¼
    å¯¹äºI p v ï¼å¦æèè®¾ä¸ä¸ªç¹Xn=0,åå¯ä»¥çæ I p n v  ï¼ä¸0å¼æï¼
    æä»¥å¯¹äºææé£äºIï¼é½æ¯a^b=vï¼ä¸¤ä¸ªä¸¤ä¸ªçï¼è¿å¸¦çææ
    æä»¥è®¾val[i]=Xi^Xfa[i]  è·ä¸é¢ä¸æ ·æè¿å¸¦ææ  fa[i]ä¸ºiçç¶äº²
    è¿æ ·ï¼
    1) I p q v
    åfind
    å¦æp qå¨åä¸éåï¼å¤æ­æ¯å¦æXp^Xq=v  ä¸æ¯çè¯çç¾
    å¦åï¼åå¹¶  æ³¨æèè®¾çç¹nè¦å§ç»ä¿æä¸ºæ ¹
    2)Q k p1pk
    Xp1 ^ Xp2  ^ Xpk
    è½¬åä¸ºï¼
    val[p1] ^ val[p2]   ^ val[k]   ^   (Xfa[p1] ^ Xfa[p2]  ^ Xfa[pk])
    val[pi]å·²ç¥ï¼åªéå¤æ­Xfa[pi]æ¯å¦å·²ç¥
    ç±äºæ¯å¼æï¼å¥æ°ä¸ªXfa[pi]æéå¤æ­ãå¤æ­æ¹æ³ä¸ºçä»çæ ¹æ¯ä¸æ¯Xnå³å¯
        
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 20010;
int fa[MAXN],val[MAXN];
int n,q;
void init(int n)
{
    for(int i=0;i<=n;i++)
    {
        val[i]=0;
        fa[i]=i;
    }
}
int find(int a)
{
    if(a!=fa[a])
    {
        int t=fa[a];
        fa[a]=find(fa[a]);
        val[a]^=val[t];
    }
    return fa[a];
}

bool unin(int a,int b,int v)
{
    int ra=find(a);
    int rb=find(b);
    if(ra==rb)
    {
        return v==(val[a]^val[b]);
    }
    if(ra==n)swap(ra,rb);
    fa[ra]=rb;
    val[ra]=val[a]^val[b]^v;
    return true;
}

char cmd[MAXN];

int main()
{
    //freopen("in","r",stdin);
    int t=1;
    while(scanf("%d%d",&n,&q),n)
    {
        printf("Case %d:\n",t++);
        init(n);
        int fact = 0;
        bool err = false;
        for(int i=0;i<q;i++)
        {
            scanf(" %c",&cmd[0]);
            if(err){gets(cmd);continue;}
            if(cmd[0]=='I')
            {
                gets(cmd);//éè¦è¿æ ·å­
                fact++;
                int x,y,v;
                if(sscanf(cmd,"%d%d%d",&x,&y,&v)==2)//sscanf()   ç´æ¥scanf()ä¼éä¸ç¥ä¸ºå¥
                {
                    swap(y,v);
                    y=n;
                }
                if(!unin(x,y,v))
                {
                    err = true;
                    printf("The first %d facts are conflicting.\n",fact);
                }
            }
            else
            {
                int k,x,ans=0,pos=-1,flag=true;
                vector<pair<int,int> > V;
                scanf("%d",&k);
                for(int i=0,jj;i<k;i++)
                {
                    scanf("%d",&x);
                    int rx=find(x);
                    rx=find(x);
                    ans^=val[x];
                    for(jj=0;jj<V.size();jj++)
                    {
                        if(V[jj].first==rx)break;
                    }
                    if(jj==V.size())V.push_back(make_pair(rx,1));
                    else V[jj].second++;
                }
                for(int j=0;j<V.size();j++)
                {
                    if(V[j].second&1)
                    {
                        if(V[j].first!=n){flag=false;break;}
                    }
                }
                  if(flag)printf("%d\n",ans);
                else puts("I don't know.");
            }
        }
        puts("");
    }
    return 0;
}