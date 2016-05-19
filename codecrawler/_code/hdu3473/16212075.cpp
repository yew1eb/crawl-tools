/***************
hdu3473
2016.1.29
561MS 30344K 2956 B C++
***************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000010;
int sorted[MAXN];   //å¯¹åéåä¸­åç´ æåºåçå¼
int val[30][MAXN];  //valè®°å½ç¬¬kå±å½åä½ç½®çå¼
int toleft[30][MAXN];  //è®°å½åç´ æå¨åºé´å½åä½ç½®åçåç´ è¿å¥å°å·¦å­æ çä¸ªæ°
long long sum[30][MAXN];  //è®°å½åç´ æå¨åºé´å½åä½ç½®åçåç´ è¿å¥å°å·¦å­æ çåç´ å
int n,t,cnt,m,x,y;
long long lsum,rsum;
int lnum,rnum;
void build(int l, int r, int d) {
    if (l == r) return ;
    int mid = (l + r) >> 1;
    int same = mid - l + 1;
    for (int i=l; i<=r; i++)
        if (val[d][i] < sorted[mid])
            same--;
    int lp = l, rp = mid+1;
    for (int i=l; i<=r; i++) {
        if (i == l) sum[d][i]=toleft[d][i] = 0;
        else toleft[d][i] = toleft[d][i-1],sum[d][i]=sum[d][i-1];
        if (val[d][i] < sorted[mid]) {
            toleft[d][i]++;
            val[d+1][lp++] = val[d][i];
            sum[d][i]+=val[d][i];
        }
        else if (val[d][i] > sorted[mid])
        {
            val[d+1][rp++] = val[d][i];
        }
        else {
            if (same) {
                same--;
                toleft[d][i]++;
                val[d+1][lp++] = val[d][i];
                sum[d][i]+=val[d][i];
            }
            else
            {
                val[d+1][rp++] = val[d][i];
            }
        }
    }
    build(l, mid, d+1);
    build(mid+1, r, d+1);
}
int query(int a, int b, int k, int l, int r, int d) {
    if (a == b) return val[d][a];
    int mid = (l + r) >> 1;
    int s, ss;
    long long sss;
    if (a == l) {
        s = toleft[d][b];
        ss = 0;
        sss=sum[d][b];
    }
    else {
        s = toleft[d][b] - toleft[d][a-1];
        ss = toleft[d][a-1];
        sss=sum[d][b]-sum[d][a-1];//ä¸ºå¥æ²¡ç®¡å³åºé´çäºï¼å ä¸ºsumæ°ç»å¨å­çæ¯âå½ååºé´æ­¤æ°ä¹åè¿å¥å·¦å­æ çåç´ åâ
        //åå³åºé´æ²¡å³ç³»åã
    }

    if (s >= k) {
        a = l + ss;
        b = l + ss + s - 1;
        return query(a, b, k, l, mid, d+1);
    }
    else {
        lnum+=s;//æ¢ç¶è¿å¥è¿ä¸ªelseäº è¯´æåé¢è¿å¥å·¦å­æ çä¸ªæ°å°äºk é£ä¹k-thå·¦ä¾§çä¸ªæ°è¯å®è¦+[a,b]ä¸­è¿å¥å·¦å­©å­çä¸ªæ°ï¼å³+s
        lsum+=sss;//åçï¼k-thå·¦ä¾§æ°ä¹åå¿ç¶è¦å ä¸ï¼åºé´[a,b]ä¸­å°äºç¬¬kå¤§åç´ å¼ä¹åï¼å³sss
        a = mid+1 + a - l - ss;
        b = mid+1 + b - l - toleft[d][b];
        return query(a, b, k-s, mid+1, r, d+1);
    }
}
long long s[MAXN];
int main()
{
    //freopen("cin.txt","r",stdin);
    cnt=1;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case #%d:\n",cnt++);
        scanf("%d",&n);
        s[0]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&sorted[i]);
            val[0][i]=sorted[i];
            s[i]=s[i-1]+sorted[i];
        }
        sort(sorted+1,sorted+n+1);
        build(1,n,0);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d",&x,&y);
            x++;y++;
            lsum=lnum=0;
            int ave=query(x,y,(y-x+2)/2,1,n,0);
            rnum=y-x+1-lnum;//è¿ä¸ªåºé´éé¤äºè¿å¥å·¦è¾¹çå°±æ¯è¿å¥å³è¾¹ç
            rsum=s[y]-s[x-1]-lsum;//sæ°ç»å¨å­çæ¯æªæ­¢å°è¿ä¸ªæ°ä¸ºæ­¢çææåç´ å
            printf("%I64d\n",rsum-lsum+(long long)(lnum-rnum)*ave);//
        }
        puts("");
    }
    return 0;
}
